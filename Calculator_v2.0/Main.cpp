#include "Evaluate.h"
#include "Log.h"
#include <Windows.h>
#include <iostream>

int main()
{
	while (true)
	{
		Evaluate eva(Log::logTokens());
		
		system("pause");

		//detect if escape key is pressed
		if (GetAsyncKeyState(27))
			exit(0);

		std::cout << std::endl;

		Sleep(100);
	}

	return 0;
}