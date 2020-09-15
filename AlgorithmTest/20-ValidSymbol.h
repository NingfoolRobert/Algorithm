#pragma once


#include <stack>
#include <string.h>
#include <iostream>

using namespace  std;
class C20Solution {

public:
	C20Solution(){}
	virtual ~C20Solution() {}
public:
	bool isValid(string s);
};

bool C20Solution::isValid(string s)
{
	if (s.length() % 2 == 1 || s.length() <= 1) return false;
	std::stack<char>  tmp;
	bool bRet = false;
	tmp.push(s.at(0));
	for (auto i = 1; i < s.length(); ++i)
	{
		bRet = false;
		char chTmp = s.at(i);
		
		char ch; 
		if(tmp.size() > 0)
			ch = tmp.top();
	
		switch (chTmp)
		{
			case ')':
				if (ch == '(')
					bRet = true;
				break;
			case '}':
				if (ch == '{')
					bRet = true;
				break;
			case ']':
				if (ch == '[')
					bRet = true;
				break;
			default:
				break;
		}

		if (bRet && tmp.size() )
			tmp.pop();
		else
			tmp.push(chTmp);
	}
	
	return tmp.size() == 0;
}
