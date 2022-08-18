#pragma once

#include "Vector4D.h"
#include "Color.h"

struct Light
{
	Vector4D Origin;
	float	Bright;
	Color Color;
};
