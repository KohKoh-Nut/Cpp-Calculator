#include "Log.h"

std::string Log::logTokens()
{
	std::cout << "Enter your expression: ";

	std::string tokens;
	std::cin >> tokens;

	return tokens;
}

void Log::logResult(double value)
{
	std::cout << "The result is: " << value << std::endl;
}