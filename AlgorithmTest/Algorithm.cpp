// Algorithm.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "PaperMoneyChange.h"
//#include "07-Reverse.h"
//#include "98-IsValidBST.h"
/*#include "06-ZConvert.h"*/
/*#include "05-LongestPalindrome.h"*/
//#include "StrFunc.h"
//#include "BinarySearch.h"
//#include "ListFunc.h"

//#include "MinCutPalindrome.h"

//#include "12-IntToRoman.h"
//#include "50-Pow.h"

//#include "14-longestCommonPrefix.h"
//#include "15-threeSum.h"

void func()
{
	static int val;
}
int Add_n(int n)
{
	static int i = 100;
	i += n;
	return i;
}

class A
{
public: 
	A(void) { printf("constuctor A ]\n"); }
protected:
	virtual ~A(void) { printf("Deconstructor A \n"); }

private:
	int m_nval;
};



int _tmain(int argc, _TCHAR* argv[])
{

// 	int nTest = Add_n(10);
// 	std::cout << nTest << std::endl;
// 	nTest = Add_n(10);
// 	std::cout << nTest << std::endl;
// 
// 	char szTmp[56] = { 0 };
// 	strcat(szTmp, "helloworld");
// 
// 	float flValue = 0;
// 	
// 	if (flValue > -1e-6 && flValue <= 1e-6)
// 	{
// 		std::cout << "Test" << std::endl;
// 	}

	//StrFunc strf;
	//std::cout << strf.myAtoi("2147483648") << std::endl;

	//std::cout << strf.strstr_28("hello", "ll") << std::endl;
	//cout << strf.strstr_KMP("abaabaabbabaaabaabbabaab", "abaabbabaab") << endl;

// 
// 	SingleList List;
// 	List.TestSingleList();

	//Solution solut;
	///solut.TestMinCut();
// 	solut.TestIntToRoman();
// 	solut.TestRomanToInt();
// 	solut.TestSearch();
// 	LCP lcpTmp;
// 	lcpTmp.TestLCP();
		
// 	std::string str("ningbeifei");
// 	std::string strTest(str, 1, 5);
// 	cout << strTest << endl;
// 	CThreeSum thre;
// 	thre.TestThreeSum_0();

	system("pause");

	return 0;
}

