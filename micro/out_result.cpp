#include "out_result.h"
#include "Int_calc.h"
#include "string_calc.h"


#include <fstream>
#include <string.h>




out_result::out_result(std::string name)
{

}

out_result::~out_result()
{

}

bool out_result::init(std::string f1, std::string f2)
{
	file_[0] = create_input(0, f1);
	file_[1] = create_input(0, f2);
	if (nullptr == file_[0] || nullptr == file_[1]
		|| !file_[0]->is_open() || !file_[0]->is_open())
	{
		printf("input file open init or open fail.");
		return false;
	}
	//
	//Input1, Input2 
	std::string input1, input2;
	
	int ret = get_calc_type(input1, input2);
	calc_ = create_calc(ret);
	if (calc_ == nullptr)
	{
		printf("memory error, create calc fail.");
		return false;
	}
	
	return true;
}

int out_result::get_calc_type(std::string l1, std::string l2)
{
	if (l1 != l2)
		return 0;
	
	if (strncmp(l1.c_str(), "Int_", 4) == 0)
		return 1;
	else if (strncmp(l1.c_str(), "String_", 7) == 0)
		return 2;
	


	return 0;
}

void out_result::calc()
{
	std::ofstream of(name_, std::ostream::out);
	if (!of.is_open())
	{
		printf("open file fail. file:%s", name_.c_str());
		return;
	}
	


	std::string out = "Diff";
	of << out << std::endl;
	std::string l1, l2;
	while (l1.length() || l2.length())
	{
		out = calc_->calc_line(l1, l2);
		of << out << std::endl;
	}

	of.close();
	
	printf("parse success...");
}

calc_base* out_result::create_calc(int _type)
{
	switch (_type)
	{
	case 1:
		return new int_calc;
	case 2:
		return new string_calc;
	default:
		break;
	}
	return nullptr;
}

input_base* out_result::create_input(int _type, std::string name)
{
	return new input_base(name);
}
