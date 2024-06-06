#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "IOError.h"
#include "Variables.h"
#include <cmath>
#include <string>
#include <array>

//a class to take in mathematical functions
class Functions
{
public:
	//an array for all the functions in alphabetical order
	static const std::string functs[];

	//method to determine which function it is
	static void getFunction(std::string func);

	//evaluate the function and storing it
	static void evaFunction(int sCase);
};

#endif