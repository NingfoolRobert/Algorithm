#pragma once


/*


828. ͳ���Ӵ��е�Ψһ�ַ�
���Ƕ�����һ������ countUniqueChars(s) ��ͳ���ַ��� s �е�Ψһ�ַ���������Ψһ�ַ��ĸ�����

���磺s = "LEETCODE" �������� "L", "T","C","O","D" ����Ψһ�ַ�����Ϊ����ֻ����һ�Σ����� countUniqueChars(s) = 5 ��

���⽫�����һ���ַ��� s ��������Ҫ���� countUniqueChars(t) ���ܺͣ����� t �� s �����ַ���������������֤����ֵΪ 32 λ������

ע�⣬ĳЩ���ַ����������ظ��ģ�����ͳ��ʱҲ����������Щ�ظ������ַ�����Ҳ����˵�������ͳ�� s ���������ַ����е�Ψһ�ַ�����
*/

#include <vector>
#include<unordered_set>
#include <unordered_map>

#include <iostream>
#include <stdio.h>
#include <stdlib.h>


using namespace std;
class Solution28 {
public:
	int uniqueLetterString(string s) {
		vector<pair<int, int>> charLastIdx(26, pair<int, int>(-1, -1));     // ÿ��λ�ô洢��ӦԪ�ص����ϸ�����λ�ú��ϸ�����λ�ã���ʼ��-1��ʾδ����
		int res = 0;    // ���ֵ
		int n = s.size();
		for (int i = 0; i < n; i++) {
			auto& p = charLastIdx[s[i] - 'A'];  // ��ȡ��ǰ�ַ�λ����Ϣ
			if (p.second != -1) {
				// ֻҪ��ǰ�ַ�֮ǰ���ֹ������ǿ��Լ���֮ǰ���ֵ��ַ���Ϊ�м��ַ�������ͳ�ƵĹ���
				res += (p.second - p.first) * (i - p.second);
			}
			p.first = p.second;     // �����ַ�����λ����Ϣ
			p.second = i;
		}
		// ����ַ��г��ֹ�����ÿ���ַ������ֵ�λ��Ϊ�м��ַ���ͳ���乱��
		for (auto p : charLastIdx) {
			if (p.second != -1) {
				res += (p.second - p.first) * (n - p.second);
			}
		}
		return  res;
	}
};