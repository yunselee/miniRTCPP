#pragma once
#include "cam.h"
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
	
	float mAmbientRatio;
	Color mAmbientColor;
	Cam mCam;
	std::vector<Light> mLights;
	std::vector<Object> mObjects;
};
