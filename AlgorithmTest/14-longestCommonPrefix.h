#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
/*
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1 :

输入: ["flower", "flow", "flight"]
	输出 : "fl"

*/




class LCP
{
public:
	string LongestCommonPrefix_Scan(vector<string>& strs);
	string LongestCommonPrefix_Binary(vector<string>& strs);
	void TestLCP();
protected:
	string LongestCommonPrefix(string str1, string str2);
	string LongestCommonPrefix_Binary(vector<string>& strs,int nlow ,int nHight);
};

std::string LCP::LongestCommonPrefix_Scan(vector<string>& strs)
{
	int nSize = strs.size();
	if (nSize == 0)
		return "";
	else if (nSize == 1)
		return strs[0];
	string strTmp = strs[0];
	string str;
	for (int iLoop = 1; iLoop < nSize; ++iLoop)
	{
		str = LongestCommonPrefix(strTmp, strs[iLoop]);
		strTmp = str;
	}
	return str;
}

std::string LCP::LongestCommonPrefix_Binary(vector<string>& strs)
{
	if (0 == strs.size())
		return "";
	return LongestCommonPrefix_Binary(strs, 0, strs.size() - 1);
}

std::string LCP::LongestCommonPrefix_Binary(vector<string>& strs, int nlow, int nHight)
{
	if (nlow == nHight)
		return strs[nlow];
	else
	{
		int mid = nlow + (nHight - nlow) / 2;
		string lcpLeft = LongestCommonPrefix_Binary(strs, nlow, mid);
		string lcpRight = LongestCommonPrefix_Binary(strs, mid + 1, nHight);
		return LongestCommonPrefix(lcpLeft, lcpRight);
	}
}

void LCP::TestLCP()
{
	vector<string> strs;
	strs.push_back("flower");
	strs.push_back("flow");
	strs.push_back("flight");
	cout << LongestCommonPrefix_Scan(strs) << endl;
	cout << LongestCommonPrefix_Binary(strs) << endl;
}

std::string LCP::LongestCommonPrefix(string str1, string str2)
{
	int nlen1 = str1.length();
	int nlen2 = str2.length();
	if (nlen2 == 0 || nlen1 == 0)
		return "";
	string str;
	int nSize = std::min(nlen2, nlen1);
	for (int iLoop = 0;iLoop < nSize ;++iLoop)
	{
		if (str1.at(iLoop) == str2.at(iLoop))
			str += str1.at(iLoop);
		else
			break;
	}
	
	return str;
}

