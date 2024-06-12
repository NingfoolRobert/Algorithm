#include "Int_calc.h"

int_calc::int_calc()
{

}

int_calc::~int_calc()
{

}

std::string int_calc::calc_line(std::string& inl1, std::string& inl2)
{
	int ret = atoi(inl1.c_str()) - atoi(inl2.c_str());

	return  std::to_string(ret);
}
