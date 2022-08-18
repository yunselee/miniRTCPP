#include "Scene.h"
#include <cstdlib>
#include <fstream>
#include <iostream>

static const char* extension = "rt";

//Scene* instance = nullptr;

Scene::Scene() : mAmbientRatio(0)
{}

Scene::Scene(const std::string& fileName) : mAmbientRatio(0)
{
	if (fileName.substr(fileName.find_last_of(".") + 1) != extension)
	{
		std::cout << "File extention error file end with .rt " << std::endl;
		exit(1);
	}
	std::ifstream readFile(fileName);
	try
	{
		if (!readFile.is_open())
		{
			std::cout << "File not exist" << std::endl;
			exit(1);
		}
		for(std::string line; getline(readFile, line); )
		{

		}
	}
	catch (const std::exception& e)
	{
		std::cout << "Something File error " << std::endl;
		std::cout << e.what() << std::endl;
		exit(1);
	}
}

Scene* Scene::instance = nullptr;

void Scene::Init(const std::string& fileName)
{
	if (Scene::instance == nullptr)
	{
		Scene::instance = new Scene(fileName);
	}
}

Scene* Scene::GetInstance()
{
	return instance;
}

void Scene::AddLight(Light light)
{
	mLights.push_back(light);
}

void Scene::AddObject(Object object)
{
	mObjects.push_back(object);
}
