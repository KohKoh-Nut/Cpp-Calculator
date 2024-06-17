#include "Format.h"

Format::Format(std::string& tokens)
{
	int length = static_cast <int> (tokens.size());

	for (int i : tokens)
	{
		exp.push_back(tokens[i]);

		exp.back() == '+';
		exp.at(exp.end() - 1) == '+'; //not work

		std::find(exp.begin(), exp.end(), "+-");

	}

	



	tokens.clear();

	while (!exp.empty())
	{
		tokens += exp.front();
		exp.pop_front();
	}
}

//while (tokens.find("++") != std::string::npos ||
//	tokens.find("+-") != std::string::npos ||
//	tokens.find("-+") != std::string::npos ||
//	tokens.find("--") != std::string::npos)
//{
//	//check for consequtive '+' and '-'
//	if (tokens.find("+-") != std::string::npos)
//	{
//		exp.push_back('-');
//		i = tokens.find("+-") + 2;
//	}
//	else if (tokens.find("-+") != std::string::npos)
//		exp.push_back('-');
//	else if (tokens.find("++") != std::string::npos)
//		exp.push_back('+');
//	else
//		exp.push_back('+');
//
//
//}
//
//exp.push_back(tokens[i]);