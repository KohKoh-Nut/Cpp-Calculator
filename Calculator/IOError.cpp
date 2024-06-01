#include "IOError.h"

std::string IOError::input()
{
	std::cout << "Enter an expression: ";

	std::string expression;
	std::cin >> expression;

	return expression;
}

void IOError::output()
{
	std::cout << Variables::result << '\n';
}

void IOError::error()
{
	std::cout << "Error";
	exit(0);
}