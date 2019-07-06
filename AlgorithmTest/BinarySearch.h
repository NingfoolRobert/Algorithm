#pragma once
#include <iostream>
#include <math.h>
#include <vector>


using namespace std;

class Solution
{
public:
	int BinarySearchValue(std::vector<int> &Array, int nlow, int nHeigth, int nValue);

	void TestLowerBound();

	int BinarySerchLowerBound(std::vector<int>&Array, int nlow, int nHeight, int nValue);

	int BinarySearchValueFirst(std::vector<int>Array, int nvalue);

	int BinarySearchValueLast(std::vector<int>Array, int nvalue);
	
	void TestSearch();

};
