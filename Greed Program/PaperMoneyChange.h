#ifndef  _PAPERMONEYCHANGE_H_
#define  _PAPERMONEYCHANGE_H_

#include "CommonHelper.h"


//////////////////////////////////////////////////////////////////////////
//��򵥵�Ǯ���������⣺������������ǵ��ճ������к��ձ顣
//����1Ԫ��2Ԫ��5Ԫ��10Ԫ��20Ԫ��50Ԫ��100Ԫ��ֽ�ҷֱ���c0, c1, c2, c3, c4, c5, c6�š�
//����Ҫ����ЩǮ��֧��KԪ������Ҫ�ö�����ֽ�ң���̰���㷨��˼�룬����Ȼ��ÿһ������������ֵ���ֽ�Ҽ��ɡ�
//���ճ�������������Ȼ��ȻҲ����ô���ġ��ڳ������Ѿ����Ƚ�Value���մ�С�����˳���źá�
//
//
//////////////////////////////////////////////////////////////////////////

int single_money[7] = {1,2,5,10,20,50,100};
int number_money[7] = {2,5,0,3,4,0,4};

int nPaperCount[7]={0};

bool PaperChange(int nMoneyTotal)
{
	if(nMoneyTotal <= 0)
		return false;
	for (int iLoop = 6;iLoop>=0;++iLoop)
	{
		nPaperCount[iLoop]= min(number_money[iLoop],nMoneyTotal / single_money[iLoop]);
		nMoneyTotal = nMoneyTotal - nPaperCount[iLoop] * single_money[iLoop];
		if(nMoneyTotal == 0)
			return true;
	}
	return false;
	
}


#endif