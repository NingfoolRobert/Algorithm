#include "input_base.h"

input_base::input_base(std::string name):name_(name)
{
	file_.open(name_, std::istream::in);
}

input_base::~input_base()
{
	{ if (is_open()) file_.close(); }
}

std::string input_base::get_line()
{
	static std::string ret;
	getline(file_, ret);
	return ret;
}
