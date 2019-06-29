#pragma once


#include <iostream>
#include <assert.h>
#include <string>
#include <algorithm>



using namespace std;
class StrFunc
{
public:
	char* strcat_(char* pszDest, const char* pszSrc);
	char* strcpy_(char*pszDest, const char* pszSrc);
	int   strcmp_(const char* pszSrc, const char* pszDest);
	char* strrchr_(const char* pszDest, char chr);
	char* strchr_(const char* pszDest, char chr);
	unsigned long strtol_(const char* nptr, char** endPtr, int base);		//base[2,36]

	int  myAtoi(std::string str);

	int strstr_(const char* pszDest, const char* pszSrc);
	int strstr_28(std::string haystack, std::string needle);
	int strstr_KMP(char* pszDest, const char* pszSrc);

public:
	// 字符串分类
	/*
	["abc","cba","abba","aabb","adbd"]
	*/
	int strDivid(std::vector<char*> vecStr);
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

	void get_next(const char* pStr, int *nextArray);

private:
};

