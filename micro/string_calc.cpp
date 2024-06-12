#include "string_calc.h"

string_calc::string_calc()
{

}

string_calc::~string_calc()
{

}

std::string string_calc::calc_line(std::string l1, std::string l2)
{
	if (l1.length() != l2.length())
		return "N";
	for (auto i = 0; i < l1.length(); ++i)
	{
		if (l1.at(i) != l2.at(i))
			return "N";
	}

	return "T";
}
