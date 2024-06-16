#ifndef FORMAT_H
#define FORMAT_H

#include <string>
#include <queue>

class Format
{
private:
	std::queue <char> exp; //a queue to store the expression

public:
	//constructor that formats the expressions
	Format(std::string& tokens);
};

#endif