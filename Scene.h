#pragma once
#include "Cam.h"
#include <vector>
#include "Light.h"
#include "Object.h"
#include <string>

//Singletone
class Scene
{
public:
	static void Init(const std::string& fileName);
	static Scene* GetInstance();
	void AddLight(Light light);
	void AddObject(Object object);
private:
	static Scene* instance;
	Scene();
	Scene(const std::string& fileName);

	float getFloat(std::ifstream &readFile);
	Vector4D getVector(std::ifstream &readFile);
	Color getColor(std::ifstream &readFile);
	void checkValidCommaFormat(char a);

	float mAmbientRatio;
	Color mAmbientColor;
	Cam mCam;
	std::vector<Light> mLights;
	std::vector<Object> mObjects;
};
