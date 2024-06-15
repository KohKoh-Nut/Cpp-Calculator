#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <iomanip>
#include <sstream>
#include <string>

//a class to process the constants
class Constants
{
public:
	static const long double presetConstants[42]; //array for the constants

	//method to output the corresponding constants as string
	static std::string outputConst(int code);
};

#endif