#pragma once

#include <iostream>
#include <math.h>

using namespace std;


class Solution
{
public:
	double myPow(double dx, int n);
	void TestmyPow();
protected:
private:
};

double Solution::myPow(double dx, int n)
{
// 	if (dx <= 10e-13 && dx >= -10e-13)
// 		return 0;
// 	double nFlag = dx;
// 	if (n < 0)
// 		nFlag = 1 / dx;
// 	else if (n = 0)
// 		return 1;
// 
// 	return myPow(myPow(dx, n / 2), 2)*(abs(n) % 2 == 1 ? nFlag : 1);
	double ans = 1;
	long long llIndex = n;
	double current_value = dx;
	if (n < 0 )
	{
		current_value = 1 / dx;
		llIndex = -llIndex;
	}
	for (long long iLoop = llIndex; iLoop > 0; iLoop /= 2)
	{
		if (iLoop % 2 == 1)
			ans *= current_value;
		current_value = current_value * current_value;
	}
	return ans;
}

void Solution::TestmyPow()
{
	double dvalue = myPow(2.000, 3);
	cout << dvalue << endl;
}

