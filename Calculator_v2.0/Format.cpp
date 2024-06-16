#include "Format.h"

Format::Format(std::string& tokens)
{
	int length = static_cast <int> (tokens.size());

	for (int i{}; i < length; i++)
	{
		if ((tokens[i] == '+' && tokens[i + 1] == '-') ||
			(tokens[i] == '-' && tokens[i + 1] == '+'))
		{
			exp.push('-');
			i++;
		}
		else
		{
			exp.push('+');
			i++;
		}

		exp.push(tokens[i]);
	}
}