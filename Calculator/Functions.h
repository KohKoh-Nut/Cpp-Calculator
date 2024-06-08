#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "IOError.h"
#include "Variables.h"
#include <map>
#include <cmath>
#include <string>
#include <iostream>

//a class to take in mathematical functions
class Functions
{
public:

	static std::string funcInput; //the whole function which the user input
	static std::string function; //the function needed to be called
	static long double parameter; //the parameters of the functions

	//method to evaluate the function
	static void evaFunction(std::string func);

	//method to get which function it is
	static void getFunction();

	//method to get the parameters
	static void getPara();
};

#endif