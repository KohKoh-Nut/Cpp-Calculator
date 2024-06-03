#include "IOError.h"

void IOError::input()
{
	std::cout << "Enter an expression: ";
	std::cin >> Variables::expression;
}

void IOError::output()
{
	std::cout << "Result: " << std::setprecision(10) << Variables::result << '\n';
}

void IOError::error()
{
	std::cout << "Error";
	exit(0);
}