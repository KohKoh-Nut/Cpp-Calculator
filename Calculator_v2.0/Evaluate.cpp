#include "Evaluate.h"

int Evaluate::applyOptr(int a, int b, char op)
{
	switch (op) {
	case '+': return a + b;
	case '-': return a - b;
	case '*': return a * b;
	case '/': return a / b;
	}
}

int Evaluate::precedence(char op)
{
	if (op == '+' || op == '-')
		return 1;
	if (op == '*' || op == '/')
		return 2;
	return 0;
}

void Evaluate::calPush()
{
	int num2 = values.top();
	values.pop();

	int num1 = values.top();
	values.pop();

	char op = optr.top();
	optr.pop();

	//push value to stack
	values.push(Evaluate::applyOptr(num1, num2, op));
}

Evaluate::Evaluate(std::string tokens)
{
	int i{}; //number of tokens processed

	for (i = 0; i < tokens.length(); i++)
	{
		//skip whitespace
		if (tokens[i] == ' ')
			continue;

		//push opening brace to stack
		else if (tokens[i] == '(')
			optr.push(tokens[i]);

		//push numbers to stack
		else if (isdigit(tokens[i]))
		{
			int num{};

			//numbers with multiple digits
			while (i < tokens.length() &&
					isdigit(tokens[i]))
			{
				num = (num * 10) + static_cast <int> ((tokens[i] - '0'));
				i++;
			}

			values.push(num);

			//to correct the offset
			i--;
		}

		//closing brace encountered, solve the sub-expression
		else if (tokens[i] == ')')
		{
			while (!optr.empty() && optr.top() != '(')
				calPush();

			if (!optr.empty())
				optr.pop();
		}

		//operators encountered
		else
		{
			while (!optr.empty() && precedence(optr.top())
				>= precedence(tokens[i]))
				calPush();

			// Push current token to 'optr'.
			optr.push(tokens[i]);
		}
	}

	while (!optr.empty())
		calPush();

	//the top of the stack is the result
	Log::logResult(values.top());
}