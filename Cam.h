#pragma once
#include "Vector4D.h"

struct Cam
{
	Vector4D Origin;
	Vector4D Direction;
	float	HFOV;
	Cam(): HFOV(0)
	{

	}
};
