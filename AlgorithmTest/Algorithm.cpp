// Algorithm.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "PaperMoneyChange.h"
#include "05-LongestPalindrome.h"


int _tmain(int argc, _TCHAR* argv[])
{
	string str = "ccc";
	
	Solution solu;

//	string str1 = solu.longestPalindrome(str);
	string str1 = "cnblogs";
	string str2 = "belong";

	string strTest = solu.LongestCommonSubsequence(str1, str2);
	return 0;
}

