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

	/*二分查找变种*/
	
	// 查找第一个与key相等的元素，也就是说等于查找key值的元素有很多，返回这些元素最左边的元素的下标
	int BinarySearchLeft(std::vector<int>Array, int nval);
	
	//查找最后一个与key相等的元素，也就是等于查找key值的元素有好多个，返回这些元素最右边元素的下标
	int BinarySearchRigth(std::vector<int>Array, int nval);
	
	//找第一个等于或者大于key的元素，查找第一个等于或者大于key的元素，也就是说查找key值的元素有好多个，
	//返回这些元素最左边元素的下标；如果没有等于key值的元素，则返回大于key的最左边元素的下标。
	int BinarySearchHightBound(std::vector<int>Array, int nval);
	

	//查找第一个大于key的元素。查找第一个大于key的值，也就是说返回大于key的最左边元素的下标
	int BinarySearchfirstGreatVal(std::vector<int>Array, int nval);

	//查找最后一个等于或者小于key的元素。查找最后一个等于或者小于key的元素，也就是说等于查找key值有很多，
	//返回这些元素最右边的元素的下标；如果没有等于key值的元素，则返回小于key值的最右边元素的下标。
	int BinarySearchFirstLessVal(std::vector<int>Array, int nval);
	

	//查找最后一个等于或者小于key的元素。查找最后一个等于或者小于key的元素，也就是说等于查找key值有很多，
	//返回这些元素最右边的元素的下标；如果没有等于key值的元素，则返回小于key值的最右边元素的下标。
	int BinarySearchLastLessAEqulVal(std::vector<int>Array, int nval);


	//查找最后一个小于key的元素。查找最后一个小于key的元素，也就是说返回小于key的最右边的元素下标。
	int BinarySearchLastLessVal(std::vector<int>Array, int nval)

	

};
