#pragma once

#include <vector>
#include <string.h>
#include <stack>
#include <algorithm>



/*

给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。

输入：s = "(()"
输出：2
解释：最长有效括号子串是 "()"
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