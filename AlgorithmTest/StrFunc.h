#pragma once


#include <iostream>
#include <assert.h>

class StrFunc
{
public:
	char* strcat_(char* pszDest, const char* pszSrc);
	char* strcpy_(char*pszDest, const char* pszSrc);
	int   strcmp_(const char* pszSrc, const char* pszDest);
	char* strrchr_(const char* pszDest, char chr);
	char* strchr_(const char* pszDest, char chr);
public:
	void memset_(void* pValue, int , int nSize);

public:
	void  swap_add(int &x, int &y);		//�Ӽ�
	void  swap_memcpy(int &x, int &y);	//memcpy
	void  swap_xor(int& x, int& y);		//���  ����������int��
protected:
	int Convert(const char* pszNum);

private:
};

char* StrFunc::strcat_(char* pszDest, const char* pszSrc)
{
	assert(pszDest == NULL || pszSrc == NULL);
	
	char* p = pszDest;
	
	while (*p++);
	
	while (*p++ = *pszSrc++);
	
	return pszDest;
}

char* StrFunc::strcpy_(char*pszDest, const char* pszSrc)
{
	assert(pszDest == NULL || pszSrc == NULL);

	char* p = pszDest;

	while (*p++ = *pszSrc);
	
	return pszDest;
}

int StrFunc::strcmp_(const char* pszSrc, const char* pszDest)
{
	int nRet = 0;
	while (!(nRet = *(unsigned char*)pszSrc - *(unsigned char*)pszDest))
		pszDest++, pszSrc++;
	if (nRet < 0)
		nRet = -1;
	else if (nRet > 0)
		nRet = 1;
	return nRet;
}

char* StrFunc::strrchr_(const char* pszDest, char chr)
{
	assert(pszDest == nullptr);
	
	if (0 == strlen(pszDest))
		return nullptr;
	
	char* p = pszDest + strlen(pszDest);
	while (p != pszDest)
	{
		if (*p == chr)
			return p;
		p--;
	}

	return nullptr;
}

char* StrFunc::strchr_(const char* pszDest, char chr)
{
	assert(pszDest == nullptr);
	if (0 == strlen(pszDest))
		return nullptr;
	char* p = pszDest;
	int nSize = strlen(pszDest);
	while (nSize--)
	{
		if (*p == chr)
			return p;
	}
	return p
}

void StrFunc::memset_(void* pValue, int nValue, int nSize)
{
	assert(pValue == nullptr);

	char* pData = (char*)pValue;
	
	while (nSize--)
	{
		*pData++ = (unsigned char)nValue;
	}
}

void StrFunc::swap_add(int &x, int &y)
{
	x = x + y;
	y = x - y;
	x = x - y;
}

void StrFunc::swap_memcpy(int &x, int &y)
{
	char sztmp[10] = { 0 };
	memcpy(sztmp, &x, sizeof(x));
	memcpy(&x, &y, sizeof(y));
	memcpy(&y, sztmp, sizeof(y));
}

void StrFunc::swap_xor(int& x, int& y)
{
	x = x ^ y;
	y = x ^ y;
	x = x ^ y;
}

int StrFunc::Convert(const char* pszNum)
{
	if (pszNum == nullptr || 0 == strlen(pszNum))
		return 0;
	int nLen = strlen(pszNum);
	
	int nRet = 0;
	while (*pszNum)
	{
		int nTmp = 0;
		if (*pszNum >= 'a' && *pszNum <= 'f')
			nTmp = *pszNum - 'a' + 10;
		else if (*pszNum >= 'A' && *pszNum <= 'F')
			nTmp = *pszNum - 'A' + 10;
		else if (*pszNum >= '0' && *pszNum <= '9')
			nTmp = *pszNum - '0';
		else
			return 0;
		if (nRet > (INT_MAX >> 4))
			return 0;
		nRet = nRet * 16 + nTmp;
	}
	return nRet;
}
