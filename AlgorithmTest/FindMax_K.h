#pragma once

#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

class Solution
{
public:
	int  findMax_K(int* pValue, int nLow, int nHeight, int KPos);
	void TestFindMax_k();
protected:
	int	 QuickSork(int* pValue, int nLow, int nHeigth);
private:
};

int Solution::findMax_K(int* pValue, int nLow, int nHeight, int KPos)
{
	int mid = QuickSork(pValue, nLow, nHeight);
	//����a[mid]���Ұ�߳���
	int length_of_right = nHeight - mid + 1;
	if (length_of_right == KPos)
	{
		return pValue[mid];
	}
	else if(length_of_right > KPos)
	{
		//�Ұ�߳��ȱ�k����˵����k���Ԫ�ػ����Ұ�ߣ�������Ұ����
		return findMax_K(pValue, mid + 1, nHeight, KPos);
	}
	else
	{
		//
		return findMax_K(pValue, nLow, mid - 1, KPos - length_of_right);
	}
}

void Solution::TestFindMax_k()
{

}

int Solution::QuickSork(int* pValue, int nLow, int nHeigth)
{
	srand(unsigned time(NULL));
	int idx = rand() % ((nHeigth - nLow) / 2 + nLow);
	int nTmp = pValue[idx];
	pValue[nLow] = pValue[idx];
	pValue[idx] = nTmp;
	nTmp = pValue[nLow];
	while (nLow < nHeigth)
	{
		while (nLow < nHeigth && pValue[nHeigth] >= nTmp) nHeigth--;
		if (nLow < nHeigth) 
		{
			pValue[nLow] = pValue[nHeigth];
			nLow++;
		}
		//
		while (nLow < nHeigth && pValue[nLow] <= nTmp) nLow++;
		if (nLow < nHeigth)
		{
			pValue[nHeigth] = pValue[nLow];
			nHeigth--;
		}
	}
	//��ʱlow=high����low������ŦԪӦ���ڵ�λ�ñ�ţ�����low
	pValue[nLow] = nTmp;
	return nLow;
}

