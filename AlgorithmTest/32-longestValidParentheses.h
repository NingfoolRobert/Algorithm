#pragma once

#include <vector>
#include <string.h>
#include <stack>
#include <algorithm>



/*

����һ��ֻ���� '(' �� ')' ���ַ������ҳ����Ч����ʽ��ȷ�������������Ӵ��ĳ��ȡ�

���룺s = "(()"
�����2
���ͣ����Ч�����Ӵ��� "()"
*/


using namespace std;
class Solution32 {
public:
	int longestValidParentheses(string s) {
		stack<char> ss;
		int nLong = 0;
		int nCt = 0;
		if (s.length() <= 1) return nLong;

		char chTmp;
		for (auto i = 0;i < s.length();++i)
		{
			if (ss.empty())
			{
				ss.push(s.at(i));
			}
			else 
			{
				chTmp = ss.top();
				if (chTmp == '(')
				{
					if (s.at(i) == ')')
					{
						ss.pop();
						nCt++;
						nLong = max(nCt, nLong);
					}
					else 
					{
						ss.push(s.at(i));
					}
				}
				else
				{
					ss.push(s.at(i));
					nCt = 0;
				}
			}
		}
		return nLong * 2;
	}
};