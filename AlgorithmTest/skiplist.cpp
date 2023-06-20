#include "skiplist.h"
#include <time.h>
#include <chrono>
#include <random>

skiplist::skiplist():max_level_(1)
{
	head_ = new node_t(INT_MIN, 1);
	srand(time(0));
}


skiplist::~skiplist()
{
	auto p = head_;
	while (p)
	{
		auto d = p;
		p = p->next[0];
		delete d;
	}
}

void skiplist::insert(int val)
{
	int level = random_generate_level();
	auto p = new node_t(val, level);
	node_t** pre = new node_t*[level];
	for (int i = 0; i < level; ++i)
	{
		pre[i] = head_;
	}
	//
	node_t* cur = head_;
	for (auto  i = level - 1; i >= 0; --i)//最高层开始
	{
		//每层遍历 找到小于val的最后一个节点
		while (cur->next[i] != nullptr && cur->next[i]->val < val)
			cur = cur->next[i];
		//
		pre[i] = cur;
	}
	//
	for (size_t i = 0; i < level; i++)
	{
		p->next[i] = pre[i]->next[i];
		pre[i]->next[i] = p;
	}

	max_level_ = level > max_level_ ? level : max_level_;
	
	delete[]  pre;
	
}

void skiplist::earse(int val)
{
	node_t** pre = new node_t*[SKIP_LIST_MAX_LEVEL];
	for (auto i = 0; i < SKIP_LIST_MAX_LEVEL; ++i)
	{
		pre[i] = nullptr;
	}
	auto cur = head_;
	for (auto i = max_level_ - 1; i >= 0; i--)//最高层开始
	{
		//每层遍历 找到小于val的最后一个节点
		while (cur->next[i] != nullptr && cur->next[i]->val < val)
			cur = cur->next[i];
		//
		pre[i] = cur;
	}
	//
	if (cur->next[0] != nullptr && cur->next[0]->val == val)
	{
		auto t = cur->next[0];
		for (auto i = SKIP_LIST_MAX_LEVEL - 1; i >= 0; i--)
		{
			if (pre[i] == nullptr)
				continue;
			//
			if (pre[i]->next[i] != nullptr && pre[i]->next[i]->val == val)
				pre[i]->next[i] = pre[i]->next[i]->next[i];
		}
		delete t;
	}
	//
	while (max_level_ > 1 && head_->next[max_level_ - 1] == nullptr)
		--max_level_;
	delete[] pre;
}

int skiplist::rank(int val)
{
	node_t*  p = head_;

	int r = 0;
	while (p->next[0] != nullptr && p->next[0]->val < val)
	{
		p = p->next[0];
		r++;
	}
	return r;
}

int skiplist::rank(int val, node_t*& lower, node_t* &upper)
{
	lower = lower_bound(val);
	upper = upper_bound(val);
	return rank(val);
}

node_t* skiplist::get(int idx)
{
	node_t*  p = head_;
	int r = 0;
	while (p->next[0] != nullptr && --idx)
	{
		p = p->next[0];
	}
	//
	if (idx == 0)
		return p;
	
	return nullptr;
}

node_t* skiplist::find(int key)
{
	auto p = head_;
	for (size_t i = 0; i < max_level_; i++)	// lower_bound
	{
		while (p->next[i] && p->next[i]->val < key)
			p = p->next[i];
	}

	if (p->next[0] != nullptr && p->next[0]->val == key)
	{
		return p->next[0];
	}
	
	return nullptr;
}

void skiplist::print()
{
	for (auto i = max_level_ - 1; i >=0; --i)
	{
		auto p = head_->next[i];
		printf("Level %d: %d", i, head_->val);
		while (p)
		{
			printf("-> %d", p->val);
			p = p->next[i];
		}

		printf("\n");
	}
	printf("\n");
}

size_t skiplist::level()
{
	return max_level_;
}

int skiplist::random_generate_level()
{
	int level = 1;
	const unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();	//获取系统时间戳，单位微秒(microsecond)。
	std::default_random_engine generator(seed);	//系统时间戳作为种子
	std::uniform_real_distribution<float> distribution(0, 1);
	float random_num = distribution(generator);	//均匀分布，生成区间[0,1]的浮点数
	while (random_num < rate_ && level < SKIP_LIST_MAX_LEVEL) {	//模拟每一次都是50%的概率小于probability
		random_num = distribution(generator);
		++level;
	}
	return level;
}

node_t* skiplist::lower_bound(int val)
{
	node_t*  p = head_;
	for (auto i = max_level_ - 1; i >= 0; i--)//最高层开始
	{
		//每层遍历 找到小于val的最后一个节点
		while (p->next[i] != nullptr && p->next[i]->val < val)
			p = p->next[i];
	}
	return p;
}

node_t* skiplist::upper_bound(int val)
{
	node_t*  p = head_;
	for (auto i = max_level_ - 1; i >= 0; i--)//最高层开始
	{
		//每层遍历 找到小于val的最后一个节点
		while (p->next[i] != nullptr && p->next[i]->val <= val)
			p = p->next[i];
	}
	//
	return p->next[0];	//第一个大于 val
}
