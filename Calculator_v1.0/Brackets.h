#ifndef BRACKETS_H
#define BRACKETS_H

#include "Count.h"
#include "Store.h"
#include "Expression.h"
#include "AddSub.h"
#include "MultDiv.h"
#include "Orders.h"
#include "Format.h"
#include "Variables.h"

//a class to process brackets
class Brackets
{
public:
	//method to process brackets
	static void doBrackets();

	//method to process incomplete set of brackets
	static void incomSet();

	//method to process complete set of brackets
	static void comSet();
};

#endif