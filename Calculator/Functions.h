#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <cmath>
#include <string>
#include <array>

//a class to take in mathematical functions
class Functions
{
public:
	static const char functs[];

	//method to determine which function it is
	static void getFunction(std::string func);
};

#endif