#pragma once

#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

class  Solution
{
public:
	string IntToRoman(int nValue);
	int	RomanToInt(string str);
	
	void TestIntToRoman();
	void TestRomanToInt();
protected:
private:
};
/*
罗马数字包含以下七种字符： I， V， X， L，C，D 和 M。

字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
*/
std::string Solution::IntToRoman(int nValue)
{	
	string Bit1[] = { "","I","II","III","IV","V","VI","VII","VIII","IX" };
	string Bit10[] = { "","X","XX","XXX","XL","L","LX","LXX","LXXX","LC" };
	string Bit100[] = { "","C","CC","CCC","CD","D","DC","DCC","DCCC","LM" };
	string Bit1000[] = { "","M","MM","MMM" };

	return Bit1000[nValue / 1000] + Bit100[(nValue % 1000) / 100] + Bit10[(nValue % 100) / 10] + Bit1[(nValue % 10)];
}

int Solution::RomanToInt(string str)
{
	//map<string, int> mapRoman;
	unordered_map<string, int> mapRoman;
	mapRoman["I"] = 1;
	mapRoman["IV"] = 4;
	mapRoman["V"] = 5;
	mapRoman["IX"] = 9;
	mapRoman["X"] = 10;
	mapRoman["XL"] = 40;
	mapRoman["L"] = 50;
	mapRoman["XC"] = 90;
	mapRoman["C"] = 100;
	mapRoman["CD"] = 400;
	mapRoman["D"] = 500;
	mapRoman["CM"] = 900;
	mapRoman["M"] = 1000;

	int nAns = 0;
	int nIndex = 0;
	int nlen = str.length();
	while (nIndex < nlen)
	{
		if (nIndex + 1 < nlen && mapRoman.count(str.substr(nIndex, 2)))
		{
			string strTest = str.substr(nIndex, 2);
			nAns += mapRoman[strTest];
			nIndex += 2;
		}
		else
		{
			string strTest = str.substr(nIndex, 1);
			nAns += mapRoman[strTest];
			nIndex += 1;
		}
	}
	return nAns;
}

void Solution::TestIntToRoman()
{
	string str = IntToRoman(3509);
	cout << str << endl;
}

void Solution::TestRomanToInt()
{
	string str = "MCMXCIV";
	cout << RomanToInt(str) << endl;
}

