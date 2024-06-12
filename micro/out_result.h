#pragma once

#include "calc_base.h"
#include "input_base.h"


class out_result
{
public:
	out_result(std::string name);
	~out_result();

public:
	bool	init(std::string f1, std::string f2);

	//
	int		get_calc_type(std::string l1, std::string l2);
	//
	
	void	calc();

private:
	calc_base*	create_calc(int _type);

	input_base* create_input(int _type, std::string name);
	
private:
	calc_base*		calc_;
	std::string		name_;

	input_base*		file_[2];
};

