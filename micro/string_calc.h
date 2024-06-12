#pragma once
#include "calc_base.h"



class string_calc :
	public calc_base
{
public:
	string_calc();
	virtual ~string_calc();

public:
	virtual std::string  calc_line(std::string l1, std::string l2);


};

