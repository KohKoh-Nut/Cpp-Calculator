#include "Functions.h"

const std::string Functions::functs[]
{
	"sin",
	"cos",
	"tan",
	"diff",
	"intg",
	"logb",
	"log2",
	"log10",
	"ln",
	"exp",
	"asin",
	"asinh",
	"acos",
	"acosh",
	"atan",
	"atanh",
	"sinh",
	"cosh",
	"tanh"
};

void Functions::getFunction(std::string func)
{
	int index{};

	do
	{
		if (func == functs[index])
			evaFunction(index);
		index++;
	} while (func != functs[index]);
}

void Functions::evaFunction(int sCase)
{
	switch (sCase)
	{
	case 0:
	}
	
	//another function to take in the parameters
	//special case for integration
}