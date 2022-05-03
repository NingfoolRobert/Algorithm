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
		int maxans = 0;
		stack<int> stk;
		stk.push(-1);
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(') {
				stk.push(i);
			}
			else {
				stk.pop();
				if (stk.empty()) {
					stk.push(i);
				}
				else {
					maxans = max(maxans, i - stk.top());
				}
			}
		}

		return maxans;
	}

	int longestValidParentheses2(string s) {
		vector<int>  dp(s.size(), 0);
		int maxans = 0;
		for (auto i = 1; i < s.size(); ++i)
		{
			if (s.at(i) == ')')
			{
				if (s.at(i - 1) == '(')
					dp[i] = dp[i - 1] + 2;
				else if(i - dp[i - 1] > 0 && s.at(i - dp[i - 1] - 1) == '(')
					dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;

				maxans = max(maxans, dp[i]);
			}
		}
		return maxans;
	}
};