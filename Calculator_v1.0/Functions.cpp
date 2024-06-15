#include "Functions.h"

std::string Functions::funcInput;
std::string Functions::function;
long double Functions::parameter;
int Functions::mode;
char Functions::degRad;

void Functions::evaFunction(std::string func)
{
	std::string expressionAf{ Variables::expression };
	Variables::expression = func;
	Count::calStringSize();
	funcInput = func;
	getFunction();
	getPara();

	//for the map of the functions
	typedef long double (*FnPtr)(long double);

	//all of the functions
	std::map<std::string, FnPtr> myMap;
	myMap["sin"] = sin;
	myMap["cos"] = cos;
	myMap["tan"] = tan;
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

	//convert degree to radians
	if ((function != "log2" || function != "log10" || function != "ln" || function != "exp")
		&& degRad == 'd')
		parameter *= (3.141592653589793238462643383279 / 180);

	Variables::resultFunc = myMap[function](parameter);
	Variables::expression = expressionAf;
}

void Functions::getFunction()
{
	for (Variables::posOfFor = 0; Variables::posOfFor <= Variables::stringSize; Variables::posOfFor++)
	{
		if (funcInput[Variables::posOfFor] == ',')
		{
			Variables::posOfFor++;
			degRad = funcInput[Variables::posOfFor];
			break;
		}

		function += funcInput[Variables::posOfFor];
	}
}

void Functions::getPara()
{
	std::string para; //the string to store the parameter
	int froBra{ Variables::posOfFor }; //the position of front bracket

	//get the position of back bracket
	for (Variables::posOfFor++; Variables::posOfFor <= Variables::stringSize; Variables::posOfFor++)
	{
		if (funcInput[Variables::posOfFor] == funcInput[Variables::stringSize] + 1)
			break;
		
		para += funcInput[Variables::posOfFor];
	}

	int bacBra{ Variables::posOfFor };

	std::string expressionAf{ Variables::expression };
	int stringSizeAf{ Variables::stringSize };
	Variables::expression = para;

	//process the parameter
	Brackets::doBrackets();
	Orders::doOrders();
	MultDiv::multDiv();
	AddSub::doAddSub(1);

	parameter = Variables::resultBrac;

	//store the parameter
	Variables::expression = Store::storeSubExpBracResult(froBra + 1, bacBra - 1, expressionAf, stringSizeAf);
}