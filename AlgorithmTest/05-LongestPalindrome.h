#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;



/*
����һ���ַ��� s���ҵ� s ����Ļ����Ӵ�������Լ��� s ����󳤶�Ϊ 1000��

����: "babad"
���: "bab"
ע��: "aba" Ҳ��һ����Ч�𰸡�

Ans:
	��̬�滮
	aba 
	abba 
				true	�Ӵ�Si....Sj �ǻ��Ĵ�
	P(i,j) = 
				false	

	P(i,j) =P(i+1,j-1) && (Si == Sj)
����
		P(i,i) = true;
		P(i,i+1) = (Si == Sj)


����׶ι���ת��Ϊһϵ�е��׶����⣬���ø��׶�֮��Ĺ�ϵ�������⣬�����˽����������Ż�������·���
*/


class Solution
{
public:
	std::string longestPalindrome(string s);
};

std::string Solution::longestPalindrome(string s)
{
	int nlen = s.length();
	int** pInt = new int*[nlen];
	for (int iLoop = 0; iLoop < nlen; ++iLoop)
	{
		pInt[iLoop] = new int[nlen];
		for (int j =0 ;j< nlen;++j)
		{
			pInt[iLoop][j] = 0;
			if (iLoop == j)
				pInt[iLoop][j] = 1;
		}
	}

	
}

