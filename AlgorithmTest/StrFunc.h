#pragma once


#include <iostream>
#include <assert.h>

class StrFunc
{
public:
	char* strcat_(char* pszDest, const char* pszSrc);
	char* strcpy_(char*pszDest, const char* pszSrc);
	int strcmp_(const char* pszSrc, const char* pszDest);
public:
	void memset_(void* pValue, int 
		, int nSize);
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

void StrFunc::memset_(void* pValue, int nValue, int nSize)
{
	assert(pValue == nullptr);

	char* pData = (char*)pValue;
	
	while (nSize--)
	{
		*pData++ = (unsigned char)nValue;
	}
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
		nRet = nRet * 16 + nTmp;
	}
	return nRet;
}
