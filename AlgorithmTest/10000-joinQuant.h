#pragma once

#include<stdio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
/*
1. 有一批货物, 我们必须按顺序在 d 天从一个地方运到另一个地方.
货物重量使用数组 w 表示(数组长度小于 50000). 每一天, 我们按顺序把货物
放到车上运走, 货物重量不能超过车的最大承重量.
问: 车的最大承重量 最少是多少?
*/

class SolutionJoinQuant1 {
public:
	SolutionJoinQuant1(){}
	~SolutionJoinQuant1() {}
public:
	int	 MinShipWithDays(int weights[], int len, int d) {
		int left = 0;
		int right = 0;
		for ( int i  = 0; i < len;  ++i)
		{
			right += weights[i];				//
			if (weights[i] > left)
				left = weights[i];
		}
		int mid = 0;
		while (left  < right)
		{
			mid = left + (right - left) / 2;
			int tmp = 0;
			int day = 1;
			for (int i = 0;  i < len; i++)
			{
				tmp += weights[i];
				if (tmp > mid) {
					day++;
					i--;
					tmp = 0;
				}
			}
			//
			if (day > d)
				left = mid + 1;
			else if (day <= d)
				right = mid;
		}

		return left;
	}

	void print(std::vector<int>& vecTmp)
	{
		for (int v:vecTmp)
		{
			std::cout << v << " ";
		}
		std::cout << std::endl;
	}

	void	print(int weights[], int d, int minWeight) {
		int tmp = 0;
		std::vector<int> vecTmp;
		for (int i = 0; i < d; ++i)
		{
			tmp += weights[i];
			if (tmp <= minWeight)
				vecTmp.push_back(weights[i]);
			
			if (tmp >= minWeight) {
				print(vecTmp);
				vecTmp.clear();
			}
		}
	}

	
};

/*
小明有 N 块草莓蛋糕，小红有 M 块巧克力蛋糕(N + M < 1000)，他们都觊觎着对
	方手里的蛋糕，最终他们决定来玩一个游戏。他们分别把蛋糕暂时地放到了桌子
	上，两个人轮流从桌子上拿去蛋糕，每次允许从草莓蛋糕或者巧克力蛋糕里拿取
	「最少」一块「最多」 K 块蛋糕(不允许即拿草莓又拿巧克力蛋糕)，拿到最后一
	块蛋糕的人将赢得所有的蛋糕。假设两个小朋友都足够聪明，先拿的人是赢还是
	输呢 ?
	*/


class SolutionJoinQuant2 {
public:
	SolutionJoinQuant2() {}
	~SolutionJoinQuant2() {}
public:
	
	bool	isFirstSuccess(int n, int m, int k) {

		//
		if (n % (k + 1) == m % (k + 1))
			return false;


		//必败情况
		if (m % (k + 1) == 0 && n % (k + 1) == 0)
			return false;

		return true;
	}
	
};