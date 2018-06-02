#pragma once

#include <functional>
#include <chrono>
#include <atomic>
#include <thread>
#include <memory>
#include <mutex>
#include <condition_variable>

#include  <iostream>

using namespace std;

class Timer
{
public:
	Timer() :expired_(true), try_to_expire_(false) {}
	Timer(const Timer &t)
	{
		expired_ = t.expired_.load();
		try_to_expire_ = t.try_to_expire_.load();
	}
	~Timer()
	{
		std::cout << "Timer destructor" << std::endl;
	}

	void StartTimer(int interVal, std::function<void()> task)
	{
		if (expired_ == false)
			return;
		expired_ = false;
		std::thread([this, interVal, task]() {
		while(!try_to_expire_)	
		{ 
			std::this_thread::sleep_for(std::chrono::milliseconds(interVal));
			task();
		}
			//stop task
		{
			std::lock_guard<std::mutex>locker(mutex_);
			expired_ = true;
			expire_condition_.notify_one();
		}
		}).detach();
	}

	void Expire()
	{
		if (expired_)
		{
			return;
		}
		if (try_to_expire_)
		{
			return;
		}

		try_to_expire_ = true;
		{
			std::unique_lock<std::mutex> locker(mutex_);
			expire_condition_.wait(locker, [this] {return expired_ == true; });
			if (expired_)
			{
				//std cout<<"timer expired...<<endl;
				try_to_expire_ = false;
			}
		}
	}
	template<typename callable,class ...arguments>
	void SyncWait(int after,callable &&f,arguments&& ...args)
	{
		std::function<typename std::result_of<callable(arguments...)>::type()>task
		(std::bind(std::forward<callable>(f), std::forward<arguments>(args)...));
		std::this_thread::sleep_for(std::chrono::milliseconds(after));
		task();
	}
	template<typename callable, class ...arguments>
	void AsyncWait(int after, callable&&f, arguments&&...args)
	{
		std::function<typename std::result_of<callable(arguments...)>::type() > task
		(std::bind(std::forward<callable>(f), std::forward<arguments>(args)...));

		std::thread([after, task]()
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(after));
			task();
		}).detach();

	}

private:
	std::atomic<bool> expired_;
	std::atomic<bool> try_to_expire_;
	std::mutex mutex_;
	std::condition_variable expire_condition_;
};
