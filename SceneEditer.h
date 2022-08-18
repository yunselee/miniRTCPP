#pragma once
#include "Light.h"
#include "Object.h"
enum e_target
{
	E_NONE = 0,
	E_LIGHT,
	E_CAM,
	E_OBJ
};

//Singletone
class SceneEditer
{
	Object* selectedObject;
	Light* selectedLight;
	unsigned int edit;
	enum e_target target_scene;
	unsigned int clicked;
	int 	prev_pixel[2];
	int debug;
};

