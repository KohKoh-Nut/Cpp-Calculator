#include "IOError.h"

void IOError::input()
{
	std::cout << "Enter an expression: ";
	std::cin >> Variables::expression;
}

void IOError::output()
{
	std::cout << "Result: " << Variables::result << '\n';
}

void IOError::error()
{
	std::cout << "Error";
	exit(0);
}