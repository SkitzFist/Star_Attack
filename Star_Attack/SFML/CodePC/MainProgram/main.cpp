#include "Game.h"
#include <ctime>
#include <stdexcept>
#include <iostream>

#ifdef _DEBUG
#pragma comment(lib, "sfml-window-d.lib")
#pragma comment(lib, "sfml-system-d.lib")
#pragma comment(lib, "sfml-graphics-d.lib")
#else
#pragma comment(lib, "sfml-window.lib")
#pragma comment(lib, "sfml-system.lib")
#pragma comment(lib, "sfml-graphics.lib")
#endif

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	srand((unsigned)time(0));

	Game game;
	try
	{
		game.run();
	}
	catch (const std::runtime_error &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (...) {
		std::cerr << "Unknown Error" << std::endl;
	}
	
	return 0;
}