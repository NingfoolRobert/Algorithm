#pragma once


/*


828. 统计子串中的唯一字符
我们定义了一个函数 countUniqueChars(s) 来统计字符串 s 中的唯一字符，并返回唯一字符的个数。

例如：s = "LEETCODE" ，则其中 "L", "T","C","O","D" 都是唯一字符，因为它们只出现一次，所以 countUniqueChars(s) = 5 。

本题将会给你一个字符串 s ，我们需要返回 countUniqueChars(t) 的总和，其中 t 是 s 的子字符串。输入用例保证返回值为 32 位整数。

注意，某些子字符串可能是重复的，但你统计时也必须算上这些重复的子字符串（也就是说，你必须统计 s 的所有子字符串中的唯一字符）。
*/

#include <vector>
#include<unordered_set>
#include <unordered_map>

#include <iostream>
#include <stdio.h>
#include <stdlib.h>


using namespace std;
class Solution28 {
public:
	int uniqueLetterString(string s) {
		vector<pair<int, int>> charLastIdx(26, pair<int, int>(-1, -1));     // 每个位置存储对应元素的上上个出现位置和上个出现位置，初始化-1表示未出现
		int res = 0;    // 结果值
		int n = s.size();
		for (int i = 0; i < n; i++) {
			auto& p = charLastIdx[s[i] - 'A'];  // 获取当前字符位置信息
			if (p.second != -1) {
				// 只要当前字符之前出现过，我们可以计算之前出现的字符作为中间字符对整个统计的贡献
				res += (p.second - p.first) * (i - p.second);
			}
			p.first = p.second;     // 更新字符出现位置信息
			p.second = i;
		}
		// 如果字符有出现过，以每个字符最后出现的位置为中间字符，统计其贡献
		for (auto p : charLastIdx) {
			if (p.second != -1) {
				res += (p.second - p.first) * (n - p.second);
			}
		}
		return  res;
	}
};