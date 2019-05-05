#ifndef  _PAPERMONEYCHANGE_H_
#define  _PAPERMONEYCHANGE_H_

#include "CommonHelper.h"


//////////////////////////////////////////////////////////////////////////
//最简单的钱币找零问题：这个问题在我们的日常生活中很普遍。
//假设1元、2元、5元、10元、20元、50元、100元的纸币分别有c0, c1, c2, c3, c4, c5, c6张。
//现在要用这些钱来支付K元，至少要用多少张纸币？用贪心算法的思想，很显然，每一步尽可能用面值大的纸币即可。
//在日常生活中我们自然而然也是这么做的。在程序中已经事先将Value按照从小到大的顺序排好。
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