#pragma once

#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <map>




using namespace std;



class SolutionletterCombinations
{
public:
	std::vector<std::string> letterCombinations(std::string digits);
protected:
private:
};

std::vector<std::string> SolutionletterCombinations::letterCombinations(std::string digits)
{
	std::map<std::string, std::string> strMap;
	strMap["0"] = "";
	strMap["1"] = "";
	strMap["2"] = "abc";
	strMap["3"] = "def";
	strMap["4"] = "ghi";
	strMap["5"] = "jkl";
	strMap["6"] = "mno";
	strMap["7"] = "pqrs";
	strMap["8"] = "tuv";
	strMap["9"] = "wxyz";

	std::vector<std::string> vecStr;
	
	int nSize = digits.length();
	for (int iLoop = 0; iLoop < nSize; ++iLoop)
	{
		string strLetter;
		string strTmp = digits.substr(iLoop, 1);
		string str = strMap[strTmp];
		int nlen = str.length();
		for (int i = 0; i < nlen; ++i)
		{
			char p = str.at(i);
			for (size_t i = 0; i < 10; i++)
			{

			}
		}

	}
}

