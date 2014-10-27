#include <iostream>
#include "Engine.h"

int main()
{
	Engine* engine = new Engine();

	try
	{
	    std::cout << "initialising engine." << std::endl;
		engine->Go();
	}
	catch(char* e)
	{
		std::cout << "error: " << e << std::endl;
	}
}

