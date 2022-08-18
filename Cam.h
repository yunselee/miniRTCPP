#pragma once
#include "Vector4D.h"

struct Cam
{
	Vector4D Origin;
	Vector4D Direction;
	float	HfovRadian;
	double	Proportion;

	Cam(): HfovRadian(0), Proportion(0)
	{}
	Cam(Vector4D origin, Vector4D direction, float hfov, double proportion): Origin(origin), Direction(direction), HfovRadian(hfov), Proportion(proportion)
	{}
};
