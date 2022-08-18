#include "Scene.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <cassert>
#include "Resolution.h"

static const char* extension = "rt";
static const char* AMBIENT_LIGHTING_IDENTIFIER = "A";
static const char* CAMERA_IDENTIFIER = "C";
static const char* LIGHT_IDENTIFIER = "L";
static const char* QUDRICS_IDENTIFIER = "qr";
static const char* CYLINDER_IDENTIFIER = "cy";
static const char* PLAIN_IDENTIFIER = "p";
static const char* SPHERE_IDENTIFIER = "sp";
static const char *WHITE_SPACE = " \t\v\r\f\n";

Scene* Scene::instance = nullptr;

Scene::Scene() : mAmbientRatio(0)
{}

// format d,d,d
Vector4D Scene::getVector(std::ifstream &readFile)
{
	std::string word;
	float ret[3];
	
	std::cout << word  << std::endl;

	std::size_t sz;
	ret[0] = std::stof(word, &sz);
	checkValidCommaFormat(word[sz]);

	word = word.substr(sz);
	ret[1] = std::stod(word, &sz);
	checkValidCommaFormat(word[sz]);

	word = word.substr(sz);
	ret[2] = std::stod(word, &sz);
	return Vector4D(ret[0],ret[1],ret[2]);
}

// if Invalid Type program exit
void checkValidCommaFormat(char a)
{
	if (a != ',')
	{
		std::cout << "comma format invalid" << std::endl;
		exit(1);
	}
}
		
void checkValidColorRange(int a[3])
{
	if (
		a[0] >= 255 || a[0] < 0
		|| a[1] >= 255 || a[1] < 0 
		|| a[2] >= 255 || a[2] < 0
		)
	{
		std::cout << "color range invalid" << std::endl;
		exit(1);
	}
}


// format i,i,i
Color Scene::getColor()
{
	std::string word;
	int ret[3];
	
	std::cout << word  << std::endl;

	std::size_t sz;
	ret[0] = std::stof(word, &sz);
	checkValidCommaFormat(word[sz]);

	word = word.substr(sz);
	std::cout << word  << std::endl;
	ret[1] = std::stof(word, &sz);

	word = word.substr(sz);
	std::cout << word  << std::endl;
	ret[2] = std::stof(word, &sz);
	
	checkValidColorRange(ret);

	return Color(ret[0],ret[1],ret[2]);
}

float getFloat(std::ifstream &readFile)
{
	std::string word;
	
	const float ret = stof(word) / 180 * M_PI;
	return ret;
}

void checkValidRitio(float ratio)
{
	if(ratio > 1.0 || ratio < 0)
	{
		std::cout << "ratio range 0.0 ~ 1.0" << std::endl;
		exit(1);
	}
}

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

		for(std::string line; getline(readFile, line)   ;)
		{
			std::cout << line << std::endl; 
			if(line == AMBIENT_LIGHTING_IDENTIFIER)
			{
				const float bright = getFloat(readFile);
				checkValidRitio(bright);

				const Color color = getColor(readFile);

				mAmbientRatio = bright;
				mAmbientColor = color;
			}
			else if(line == CAMERA_IDENTIFIER)
			{
				const Vector4D origin = getVector(readFile);
				const Vector4D direction = getVector(readFile);
				const float hfovRadian = getFloat(readFile)  / 180 * M_PI;
				const double propotion = (WIN_WIDTH / 2) / tan(hfovRadian / 2);
				const Cam cam = {origin, direction, hfovRadian, propotion};
				mCam = cam;
			}
			else if(line == LIGHT_IDENTIFIER)
			{
				const Vector4D origin = getVector(readFile);
				const float bright = getFloat(readFile);
				checkValidRitio(bright);

				const Color color = getColor(readFile);

				Light light = {origin, color, bright};
				AddLight(light);
			}
			else if()
			{

			}
			else
			{
				std::cout << " Invalid Identifier " << std::endl;
				exit(1);
			}
		}
		readFile.close();
	}
	catch (const std::exception& e)
	{
		std::cout << "Something File error " << std::endl;
		std::cout << e.what() << std::endl;
		exit(1);
	}
}

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
