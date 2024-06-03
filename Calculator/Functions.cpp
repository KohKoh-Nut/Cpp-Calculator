#include "Functions.h"

const char Functions::functs[]
{
	"sin",
	"cos",
	"tan"
};

void Functions::getFunction(std::string func)
{
	int funcIndex = functs.findIndex(func);//still working

}