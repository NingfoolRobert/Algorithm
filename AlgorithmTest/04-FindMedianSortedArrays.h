#pragma once

#include <iostream>
#include <math.h>
#include <vector>

using namespace std;


/*
给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。

请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

你可以假设 nums1 和 nums2 不会同时为空。
*/



class Solution 
{
public:
	double FindMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);
};

double Solution::FindMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
	int  nSize1 = nums1.size();
	int  nSize2 = nums2.size();
	if (nSize1 > nSize2)
		return FindMedianSortedArrays(nums2, nums1);
	int nleft = 0;
	int nRight = nSize1;
	int nMedian = (nSize1 + nSize2 + 1) / 2;
	int nMedian1 = 0;
	int nMedian2 = 0;
	while (nleft < nRight)
	{
		 nMedian1 = nleft + (nRight - nleft) / 2;
		 nMedian2 = nMedian - nMedian1;
		if (nums1[nMedian1] < nums2[nMedian2 - 1])
			nleft = nMedian1 + 1;
		else
			nRight = nMedian1;
	}
	 nMedian1 = nleft;
	 nMedian2 = nMedian - nleft;

	int nCenter1 = max((nMedian1 <= 0 ? INT_MIN : nums1[nMedian1 - 1]), 
						(nMedian2 <= 0 ? INT_MIN : nums2[nMedian2 - 1]));
	if ((nSize2 + nSize1) % 2 == 1)
		return nCenter1;
	int nCenter2 = min(nMedian1 >= nSize1 ? INT_MAX : nums1[nMedian1], 
						nMedian2 >= nSize2 ? INT_MAX : nums2[nMedian2]);

	return (nCenter2 + nCenter1)*0.5;
	
}

