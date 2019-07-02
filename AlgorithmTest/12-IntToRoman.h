#pragma once

#include <iostream>
#include <math.h>
#include <string>

using namespace std;

class  Solution
{
public:
	string IntToRoman(int nValue);
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
	char szRoman[] = { 'I','V','X','L','C','D','M' };
	int	 ArrValue[] = { 1,5,10,50,100,500,1000 };
	string str;
	
	string Bit1[] = { "","I","II","III","IV","V","VI","VII","VIII","IX" };
	string Bit10[]={"","X","XX",}
}

