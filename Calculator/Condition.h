#ifndef CONDITION_H
#define CONDITION_H

//a class to process conditions
class Condition
{
public:
	int posOfFor{};
	int stringSize{};

	//method to detect error and stop execution
	void error();

	//check the condition for the method to find position of operator
	bool checkForCondition(int i);
	bool checkIfCondition(int i,char j);

	//methods to check if the character is an operator or not
	bool checkOptrAll(char i);
	bool checkOptrAddSub(char i);
	bool checkOptrMultDiv(char i);

	
};

#endif