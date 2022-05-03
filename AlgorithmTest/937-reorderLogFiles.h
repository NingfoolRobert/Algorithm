#pragma once

#include <vector>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

/*
����һ����־���� logs��ÿ����־�����Կո�ָ����ִ������һ����Ϊ��ĸ�����ֻ�ϵ� ��ʶ�� ��

�����ֲ�ͬ���͵���־��

��ĸ��־������ʶ��֮�⣬�����־���Сд��ĸ���
������־������ʶ��֮�⣬�����־����������
�밴����������־��������

���� ��ĸ��־ ������ ������־ ֮ǰ��
��ĸ��־ �����ݲ�ͬʱ�����Ա�ʶ���󣬰�������ĸ˳��������������ͬʱ������ʶ������
������־ Ӧ�ñ���ԭ�������˳��
������־������˳��

*/

using namespace std;
class Solution937 {
public:
	vector<string> reorderLogFiles(vector<string>& logs) {
		vector<string> vecans;
		for (auto i = 0; i < logs.size(); i++)
		{
			auto s = logs[i];
			
		}

		stable_sort(logs.begin(), logs.end(), [](const string& log1, const string& log2) {
			int pos1 = log1.find_first_of(" ");
			int pos2 = log2.find_first_of(" ");
			bool isDigit1 = isdigit(log1[pos1 + 1]);
			bool isDigit2 = isdigit(log2[pos2 + 1]);
			if (isDigit1 && isDigit2) {
				return false;
			}
			if (!isDigit1 && !isDigit2) {
				string s1 = log1.substr(pos1);
				string s2 = log2.substr(pos2);
				if (s1 != s2) {
				return s1 < s2;
			}
			return log1 < log2;
			}
			return isDigit1 ? false : true;
		});
		return logs;
	}
};
