#include "IOError.h"
#include <string>
#include <iostream>

std::string IOError::input()
{
	std::cout << "Enter an expression: ";

	std::string expression;
	std::cin >> expression;

	return expression;
}

void IOError::output(double result)
{
	std::cout << result << '\n';
}

void IOError::error()
{
	std::cout << "Error";
	exit(0);
}