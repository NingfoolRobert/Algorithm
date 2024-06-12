#pragma once
#ifndef _FILE_BASE_H_
#define _FILE_BASE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <iostream>




class calc_base {
public:
	calc_base(){}
	virtual ~calc_base(){}

public:
	virtual std::string	  calc_line(std::string, std::string) { return ""; }
public:
};


#endif 
