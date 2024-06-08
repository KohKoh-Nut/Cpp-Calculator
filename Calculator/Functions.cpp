#include "Functions.h"

std::string Functions::funcInput;
std::string Functions::function;
long double Functions::parameter;

void Functions::evaFunction(std::string func)
{
	funcInput = func;
	getFunction();
	getPara();

	//for the map of the functions
	typedef long double (*FnPtr)(long double);

	std::map<std::string, FnPtr> myMap;
	myMap["sin"] = sin;
	myMap["cos"] = cos;
	myMap["tan"] = tan;
	// myMap["diff"] = 
	// myMap["intg"] = 
	myMap["log2"] = log2;
	myMap["log10"] = log10;
	myMap["ln"] = log;
	myMap["exp"] = exp;
	myMap["asin"] = asin;
	myMap["asinh"] = asinh;
	myMap["acos"] = acos;
	myMap["acosh"] = acosh;
	myMap["atan"] = atan;
	myMap["atanh"] = atanh;
	myMap["sinh"] = sinh;
	myMap["cosh"] = cosh;
	myMap["tanh"] = tanh;

	if (function != "log2" || function != "log10" || function != "ln" || function != "exp")
		parameter *= (3.141592653589793238462643383279 / 180);

	Variables::resultFunc = myMap[function](parameter);
}

void Functions::getFunction()
{
	for (Variables::posOfFor = 0; Variables::posOfFor <= Variables::stringSize; Variables::posOfFor++)
	{
		if (funcInput[Variables::posOfFor] == '(')
			break;

		function += funcInput[Variables::posOfFor];
	}
}

void Functions::getPara()
{
	std::string para;

	for (Variables::posOfFor++; Variables::posOfFor <= Variables::stringSize; Variables::posOfFor++)
	{
		if (funcInput[Variables::posOfFor] == ')')
			break;
		
		para += funcInput[Variables::posOfFor];
	}

	parameter = std::stold(para);
}