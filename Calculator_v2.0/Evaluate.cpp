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
	double num2 = static_cast <double> (values.top());
	values.pop();

	double num1 = static_cast <double> (values.top());
	values.pop();

	char op = optr.top();
	optr.pop();

	//push value to stack
	values.push(Evaluate::applyOptr(num1, num2, op));
}

int Evaluate::digits(double& num, int& i)
{
	int digits{}, digitsAfDec{}; //the number of digits
	bool period{};

	//numbers with multiple digits
	while (i < tokens.length() &&
		(isdigit(tokens[i]) ||
			tokens[i] == '.'))
	{
		if (tokens[i] == '.')
		{
			period = true;
			i++;
			continue;
		}

		//converting into decimal
		num = num + (tokens[i] - '0') * pow(10, -digits);

		if (!period)
			digitsAfDec++;

		digits++;
		i++;
	}

	return digitsAfDec;
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
		else if (isdigit(tokens[i]) || tokens[i] == '.')
		{
			double num{};

			//converting back
			num *= pow(10, (digits(num, i) - 1));

			//to correct the offset
			i--;
			values.push(num);
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