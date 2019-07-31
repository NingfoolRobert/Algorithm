#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <algorithm>
#include <unordered_map>


/*
定一个未排序的整数数组，找出最长连续序列的长度。

要求算法的时间复杂度为 O(n)。

示例:

输入: [100, 4, 200, 1, 3, 2]
输出: 4
解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。
*/

using namespace std;

class CSolution
{
public:
	class unionSet {
	private:
		int ans;
		vector<int> fa;
		vector<int> size;
		unordered_map<int, int> hashMap;
		void __merge(int a, int b) {
			int aa = get(a), bb = get(b);
			if (aa == bb) return;
			fa[aa] = bb;
			size[bb] += size[aa];
			ans = max(ans, size[bb]);
		}
	public:
		unionSet(int n = 0) : ans(1), fa(n), size(n, 1) {
			for (int i = 0; i < n; i++) fa[i] = i;
		}
		int set(int i, int ind) {
			if (hashMap.find(i) != hashMap.end()) return 1;
			hashMap[i] = ind;
			return 0;
		}
		int get(int x) {
			return fa[x] = (fa[x] == x ? x : get(fa[x]));
		}
		int maxSize() {
			return ans;
		}
		void merge(int a, int b) {
			auto i = hashMap.find(b);
			if (i == hashMap.end()) return;
			__merge(a, i->second);
		}
	};
	int longestConsecutive(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		unionSet u(nums.size());
		for (int i = 0; i < nums.size(); i++) {
			if (u.set(nums[i], i)) continue;
			u.merge(i, nums[i] - 1);
			u.merge(i, nums[i] + 1);
		}
		return u.maxSize();
	}
protected:
private:
};

