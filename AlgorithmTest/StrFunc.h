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
	long strtol_(const char* nptr, char** endPtr, int base);		//base[2,36]

public:
	void memset_(void* pValue, int , int nSize);
	void* memcpy_(char* pszDest, const char* pszSrc, size_t len);
	void* memmove_(char* pszDest, const char* pszSrc, size_t len);
public:
	void  swap_add(int &x, int &y);		//加减
	void  swap_memcpy(int &x, int &y);	//memcpy
	void  swap_xor(int& x, int& y);		//异或  仅限于整数int型
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
	while (!(nRet = *(unsigned char*)pszSrc - *(unsigned char*)pszDest) && *pszDest)
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

long StrFunc::strtol_(const char* nptr, char** endPtr, int base)
{
	const char* p = nptr;
	unsigned long lRet = 0;
	int ch;
	unsigned long Overflow;
	int sign = 0, flag, LimitRemainder;
	do 
	{
		ch = *p++;
	} while (isspace(ch));

	if (ch == '-')
	{
		sign = 1;
		ch = *p++;
	}
	else if (ch == '+')
		ch = *p++;
	if (base == 0 || base == 16 && ch == '0' && (*p == 'x' || *p == 'X'))
	{
		ch = p[1];
		p += 2;
		base = 16;
	}
	if (base == 0)
		base = ch == '0' ? 8 : 10;

	Overflow = sign ? -(unsigned long)LONG_MIN : LONG_MAX;
	LimitRemainder = Overflow % (unsigned long)base;
	Overflow /= (unsigned long)base;
	
	for (lRet = 0, flag = 0;; ch = *p++)
	{
		if (isdigit(ch))
			ch -= '0';
		else if (isalpha(ch))
			ch -= isupper(ch) ? 'A' - 10 : 'a' - 10;
		else
			break;
		if(ch > base)
			break;

		if (flag <0 || lRet > Overflow || (lRet == Overflow && ch > LimitRemainder))
			flag = -1;
		else
		{
			flag = 1;
			lRet = lRet * base + ch;
		}
	}
	if (flag < 0)
		lRet = sign ? LONG_MIN : LONG_MAX;
	else if (sign)
		lRet = -lRet;

	if (endPtr != nullptr)
		*endPtr = (char*)(flag ? (p - 1) : nptr);

	return lRet;
}

void StrFunc::memset_(void* pValue, int nValue, int nSize)
{
	assert(pValue == nullptr);

	char* pData = (char*)pValue;
	
	while (nSize--)
	{
		*pData++ = (char)nValue;
	}
}

void* StrFunc::memcpy_(char* pszDest, const char* pszSrc, size_t len)
{
	if (pszDest == nullptr || pszSrc == nullptr)
		return nullptr;

	void* pRet = pszDest;
	if (pszDest < pszSrc || (char*)pszDest >= (char*)pszSrc + len)
	{
		while (len--)
		{
			*(char*)pszDest = *(char*)pszSrc;
			pszDest = (char*)pszDest + 1;
			pszSrc = (char*)pszSrc + 1;
		}
		pszDest = pRet;
	}
	else
	{
		//有内存重叠时，逆序
		pszSrc = (char*)pszSrc + len - 1;
		pszDest = (char*)pszDest + len - 1;
		while (len--)
		{
			*(char*)pszDest = *(char*)pszSrc;
			pszDest = (char*)pszDest - 1;
			pszSrc = (char*)pszSrc - 1;
		}
	}
	return pRet;
}

void* StrFunc::memmove_(char* pszDest, const char* pszSrc, size_t len)
{
	if (pszDest == nullptr || pszSrc == nullptr)
		return nullptr;

	void* pRet = pszDest;
	if (pszDest < pszSrc || (char*)pszDest >= (char*)pszSrc + len)
	{
		while (len--)
		{
			*(char*)pszDest = *(char*)pszSrc;
			pszDest = (char*)pszDest + 1;
			pszSrc = (char*)pszSrc + 1;
		}
		pszDest = pRet;
	}
	else
	{
		//有内存重叠时，逆序
		pszSrc = (char*)pszSrc + len - 1;
		pszDest = (char*)pszDest + len - 1;
		while (len--)
		{
			*(char*)pszDest = *(char*)pszSrc;
			pszDest = (char*)pszDest - 1;
			pszSrc = (char*)pszSrc - 1;
		}
	}
	return pRet;
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
