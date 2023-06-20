#pragma once

#include <stdio.h>
#include <vector>


#define  SKIP_LIST_MAX_LEVEL		32

struct node_t
{
	int							val;
	int							level;
	node_t*						next[SKIP_LIST_MAX_LEVEL];
	node_t(int v, int l) :val(v), level(l) { for (auto i = 0u; i < SKIP_LIST_MAX_LEVEL; ++i) next[i] = nullptr; }
};


class skiplist
{
public:
	skiplist();
	~skiplist();
public:
	void	insert(int val);

	void	earse(int val);
	
	int		rank(int val);
	int		rank(int val, node_t*&  lower, node_t* &upper);

	node_t*	lower_bound(int val);

	node_t*	upper_bound(int val);

	node_t*		get(int idx);

	//·µ»ØÏÂ½ç
	node_t*		find(int key);


	void	print();

	size_t	level();
protected:
	
	int			random_generate_level();

private:
	float						rate_ = 0.5;
	int							max_level_;
	node_t						*head_;
};

