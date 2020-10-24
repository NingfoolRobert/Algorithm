#pragma once


#include <vector>
#include <algorithm>
#include <iostream>


class CBDSolution
{
public:
	CBDSolution();
	~CBDSolution();

public:
	int CalculateKole(std::vector<int>& listVal);


private:

};

CBDSolution::CBDSolution()
{
}

CBDSolution::~CBDSolution()
{
}

int CBDSolution::CalculateKole(std::vector<int>& listVal)
{
	int start = 0;
	int end = 0;
	int nMax = 0;
	int result = 0;

	std::pair<int, int> left = std::make_pair(0, listVal[0]);
	std::pair<int, int> right = std::make_pair(0, listVal[0]);

	int pos = 1;
	while (pos < listVal.size())
	{
		for (auto i = pos; i < listVal.size(); ++i)
		{
			if (left.second > listVal[pos])
			{
				if (right.second <= listVal[pos])
				{
					right.first = pos;
					right.second = listVal[pos];
				}
			}
			else
			{
				right.first = i;
				right.second = listVal[pos];
				break;
			}
		}

		for (auto i = left.first + 1; i < right.first; i++)
			result += std::min(left.second, right.second) - listVal[i];

		left = right; 
		pos = right.first + 1;
	}
	return result;
// 
// 	while(start < listVal.size() - 1)
// 	{
// 		int nMax = 0;
// 		int val = 0;
// 		int pos = start + 1;
// 		for (auto i = start + 1; i < listVal.size(); i++)
// 		{
// 			if (listVal[start] <= listVal[i])
// 			{
// 				pos = i;
// 				val = listVal[i];
// 				break;
// 			}
// 
// 			if (listVal[i] > listVal[start])
// 			{
// 				//TODO start 最大值， 找出其右半部分最大值。 
// 			}
// 		}
// 		
// 		for (pos = pos - 1; pos > start; pos--)
// 			result += val - listVal[pos];
// 
// 		start = pos;
// 	}
}

