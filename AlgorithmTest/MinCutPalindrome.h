#pragma once
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;


class Solution
{
public:
	/*
	str="ABA"
	str ="A|CDCDC|DAD"
	*/
	int  MinCutPalindrome(char* pszPalindrome);

	void TestMinCut();
protected:
private:
};

int Solution::MinCutPalindrome(char* pszPalindrome)
{
	if (pszPalindrome == nullptr || 0 == strlen(pszPalindrome) )
	{
		return 0;
	}
	int nlen = strlen(pszPalindrome);
	std::vector<int> dp(nlen + 1, 0);
	dp[nlen] = -1;
	
	std::vector<std::vector<bool>> Palindrome(nlen,std::vector<bool>(nlen,false));
	

	for (int iLoop = nlen - 1; iLoop >= 0; iLoop--)
	{
		dp[iLoop] = INT_MAX;
		
		for (int j = iLoop; j < nlen; ++j)
		{
			if (pszPalindrome[iLoop] == pszPalindrome[j] && (j - iLoop < 2 || Palindrome[iLoop + 1][j - 1]))
			{
				Palindrome[iLoop][j] = true;
				dp[iLoop] = min(dp[iLoop], dp[j + 1] + 1);
			}
		}
	}
	return dp[0];
}

void Solution::TestMinCut()
{
	char szPalindrome[] = { "ACDCDCDAD" };
	int nCut = MinCutPalindrome(szPalindrome);
	cout << nCut << endl;
}
