#include "Variables.h"

int Variables::posOfFor;
int Variables::stringSize;
int Variables::numOfOptr;
int Variables::optrDone;
int Variables::optr_1;
int Variables::optr_2;
int Variables::optr_3;

double Variables::result;
double Variables::resultBrac;

std::string Variables::expression;

void Variables::reset()
{
	posOfFor = 0, stringSize = 0;
	numOfOptr = 0, optrDone = 0;
	optr_1 = 0, optr_2 = 0, optr_3 = 0;
}

void Variables::resetPOF()
{
	posOfFor = 0;
}