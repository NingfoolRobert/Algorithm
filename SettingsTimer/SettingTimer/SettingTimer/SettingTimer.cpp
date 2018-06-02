// SettingTimer.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Timer.h"


#include <iostream>
#include<string>
#include <memory.h>


using namespace std;

void EhcoFunc(std::string &s)
{
	cout << "test:" << s << endl;
}

int main()
{
	Timer T;
#if 0
	//	������ִ������
	T.StartTimer(1000, std::bind(EhcoFunc, "Hello World!"));
	std::this_thread::sleep_for(std::chrono::seconds(4));
	std::cout << "try_to_expired_timer" << endl;
	T.Expire();


	//������ִ�ж�ʱ����
	T.StartTimer(1000, std::bind(EhcoFunc, "hello c++11!"));
	std::this_thread::sleep_for(std::chrono::seconds(4));
	std::cout << "try to expire timer!" << std::endl;
	T.Expire();

	//
	std::this_thread::sleep_for(std::chrono::seconds(2));
#endif
	//
	T.SyncWait(100, EhcoFunc, "Hello");

	T.AsyncWait(1000, EhcoFunc, "World");
	std::this_thread::sleep_for(std::chrono::seconds(2));
    return 0;
}

