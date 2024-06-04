#include "Functions.h"

const char Functions::functs[]
{
	"sin",
	"cos",
	"tan"
};

long double Functions::getFunction(std::string func)
{
	switch (func[0])
	{
	case 'a':
		break;

	default:
		IOError::error();
		break;
	}

}