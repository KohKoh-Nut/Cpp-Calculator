#include "Evaluate.h"

double Evaluate::applyOptr(double a, double b, char op)
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
	int num2 = static_cast <int> (values.top());
	values.pop();

	int num1 = static_cast <int> (values.top());
	values.pop();

	char op = optr.top();
	optr.pop();

	//push value to stack
	values.push(Evaluate::applyOptr(num1, num2, op));
}

int Evaluate::digits(int& i)
{
	int num{};

	//numbers with multiple digits
	while (i < tokens.length() &&
		isdigit(tokens[i]))
	{
		num = (num * 10) + static_cast <int> ((tokens[i] - '0'));
		i++;
	}

	//to correct the offset
	i--;

	return num;
}

Evaluate::Evaluate(std::string token)
{
	int i{}; //number of tokens processed
	tokens = token;

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
			values.push(digits(i));

		else if (tokens[i] == '.')
		{
			std::ostringstream num1;
			num1 << std::setprecision(10) << static_cast <int> (values.top());
			values.pop();

			i++;

			std::ostringstream num2;
			num2 << std::setprecision(10) << digits(i);
			std::string num = num1.str() + '.' + num2.str();

			values.push(stod(num));
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
			if (values.empty())
				values.push(0);

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