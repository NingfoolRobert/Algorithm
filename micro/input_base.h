#pragma once
#include <string.h>
#include <stdlib.h>
#include <string>
#include <fstream>



class input_base
{
public:
	explicit input_base(std::string name);
	virtual ~input_base();
	
public:

	bool			is_open();
	std::string		get_line();
	
public:
	std::fstream		file_;
	std::string			name_;
};

bool input_base::is_open()
{
	return file_.is_open();
}


