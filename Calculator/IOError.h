#ifndef IOERROR_H
#define IOERROR_H

#include "Variables.h"
#include <string>
#include <iostream>

//a class for taking input, output result and detecting error
class IOError
{
public:
	//method to get input from user
	static std::string input();

	//method to output the result
	static void output();

	//method to detect error and stop execution
	static void error();
};

#endif