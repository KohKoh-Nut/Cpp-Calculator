#ifndef LOG_H
#define LOG_H

#include <string>
#include <iomanip>
#include <iostream>

//a class to output
class Log
{
public:
	//method to take user input
	static std::string logTokens();

	//method to output the result
	static void logResult(double value);
};

#endif