#pragma once

#include<stdio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
/*
1. ��һ������, ���Ǳ��밴˳���� d ���һ���ط��˵���һ���ط�.
��������ʹ������ w ��ʾ(���鳤��С�� 50000). ÿһ��, ���ǰ�˳��ѻ���
�ŵ���������, �����������ܳ���������������.
��: ������������ �����Ƕ���?
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
С���� N ���ݮ���⣬С���� M ���ɿ�������(N + M < 1000)�����Ƕ������Ŷ�
	������ĵ��⣬�������Ǿ�������һ����Ϸ�����Ƿֱ�ѵ�����ʱ�طŵ�������
	�ϣ���������������������ȥ���⣬ÿ������Ӳ�ݮ��������ɿ�����������ȡ
	�����١�һ�顸��ࡹ K �鵰��(�������ò�ݮ�����ɿ�������)���õ����һ
	�鵰����˽�Ӯ�����еĵ��⡣��������С���Ѷ��㹻���������õ�����Ӯ����
	���� ?
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


		//�ذ����
		if (m % (k + 1) == 0 && n % (k + 1) == 0)
			return false;

		return true;
	}
	
};