#pragma once

#include <iostream>
#include <vector>
#include <string>


using namespace std;

class Solution
{
public:

	void Test06();
	string convert(string s, int numRows);
protected:
private:
};

void Solution::Test06()
{

	string str = "LEETCODEISHIRING";
	string strOut = convert(str, 3);
}

/*
∞¥––º∆À„

*/

std::string Solution::convert(string s, int numRows)
{
	int nLen = s.length();
	if (nLen <= 1 || numRows <= 1)
		return s;

	vector<string>  Array(numRows,"");
	
	int nSort = 0;
	int nFlag = 1;
	for (int iLoop = 0; iLoop < nLen; ++iLoop)
	{
		char stmp = s.at(iLoop);
		Array[nSort]+=stmp;
		if (nSort == numRows - 1)
			nFlag = -1;
		else if (nSort == 0)
			nFlag = 1;

		nSort += nFlag;
	}

	string strOut;
	for (int iLoop = 0;iLoop < numRows;++iLoop)
	{
		strOut += Array[iLoop];
	}
	return strOut;
}

