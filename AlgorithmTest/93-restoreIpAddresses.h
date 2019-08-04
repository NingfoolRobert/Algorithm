#pragma once


#include <iostream>
#include <vector>
#include <string.h>
#include <map>

/*
给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。

示例:

输入: "25525511135"
输出: ["255.255.11.135", "255.255.111.35"]

*/
using namespace std;
class CSolution
{
public:
	vector<string> restoreIpAddresses(string s);
	
protected:
	bool Juage(char* pszStart, char* pszend);
	bool isVaild(char* szNums);
private:
	string s;
	vector<string> segments;
	vector<string> output;
};

std::vector<std::string> CSolution::restoreIpAddresses(string s)
{
	std::vector<string> vecIP;
	int nlen = s.length();
	if (nlen < 4 || nlen > 12)
		return vecIP;
	char szIP[15] = { 0 };
	strcpy(szIP, s.c_str());
	char* pnode1 = &szIP[1];
	char* pnode2 = &szIP[2];
	char* pnode3 = &szIP[3];
	char* pszend = szIP + nlen;
	while (true)
	{
	
		if (Juage(szIP, pnode1))
		{
			if (!Juage(pnode3, pszend))
			{
				pnode3++;
				if (pnode3 == pszend)
					break;
				continue;
			}
			else
			{
				if (!Juage(pnode2, pnode3))
				{
					pnode2++;
					pnode3 = pnode2 + 1;
					continue;
				}
				else
				{
					if (!Juage(pnode1, pnode2))
					{
						pnode1++;
						pnode2 = pnode1 + 1;
						pnode3 = pnode2 + 1;
						continue;
					}
					else
					{
						string str = szIP;
						int nPos = pnode3 - szIP;
						str.insert(nPos, 1, '.');
						int nPos = pnode2 - szIP;
						str.insert(nPos, 1, '.');
						int nPos = pnode1 - szIP;
						str.insert(nPos, 1, '.');
						vecIP.push_back(str);
						

						pnode3++;
					}
				}
			}
		}
		else
			break;
	}
}

bool CSolution::Juage(char* pszStart, char* pszend)
{
	char szTmp[4] = { 0 };
	strncpy(szTmp, pszStart, pszend - pszStart);
	
	return isVaild(szTmp);
	
}

bool CSolution::isVaild(char* szNums)
{
	int nLen = strlen(szNums);
	if (nLen > 3)
		return false;
	int nval = atoi(szNums);
	
	if (nval >= 0 && nval <= 255)
		return true;
	return false;
}

