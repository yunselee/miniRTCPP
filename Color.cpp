#include "Color.h"

Color::Color() : mRed(0), mGreen(0), mBlue(0), mAlpha(0)
{}

Color::Color(unsigned char r, unsigned char g, unsigned char b) : mRed(r), mGreen(g), mBlue(b), mAlpha(0)
{}

unsigned int Color::ToHex() const
{
	return ((unsigned int)mBlue + (mGreen << 8) + (mRed << 16));
}

Color Color::operator+(const Color& a)
{
	return Color(mRed * a.mRed, mGreen * a.mGreen, mBlue * a.mBlue);
}

Color Color::operator*(double a)
{
	return Color(mRed * a, mGreen * a, mBlue * a);
}
