#include <iostream>
#include <string>
#include "MlxManager.h"
#include "timer.h"
#include "Timer.h"
#include "Scene.h"

int main(int argc, char **argv)
{
	/*if (argc != 2 || argv == NULL)
	{
		std::cout << "Error\n\t: usage : ./miniRT <FILENAME>" << std::endl;
		return (1);
	}*/
	//std::string filename = argv[0];
	Timer::start();
	std::string filename = "colored_shaodow_test.rt";
	//MlxManager::Init(filename);
	//Scene::Init(filename);


	Timer::end("Total time");
	return 0;
}