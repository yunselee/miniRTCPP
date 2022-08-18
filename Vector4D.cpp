#include "Vector4D.h"
#include <cmath>

Vector4D::Vector4D() : mX(0), mY(0), mZ(0), mW(0)
{}
Vector4D::Vector4D(float mX, float mY, float mZ) : mX(mX), mY(mY), mZ(mZ), mW(0)
{}
Vector4D::Vector4D(float mX, float mY, float mZ, float mW) : mX(mX), mY(mY), mZ(mZ), mW(mW)
{}

Vector4D	Vector4D::operator+(const Vector4D& b) const
{
	return (Vector4D(mX + b.mX, mY + b.mY, mZ + b.mZ, mW + b.mW));
}

Vector4D	Vector4D::operator-(const Vector4D& b) const
{
	return (Vector4D(mX - b.mX, mY - b.mY, mZ - b.mZ, mW - b.mW));
}

Vector4D	Vector4D::operator*(float scalar) const
{
	return (Vector4D(mX * scalar, mY * scalar, mZ * scalar, mW * scalar));
}

Vector4D	Vector4D::operator/(float scalar) const
{
	return (Vector4D(mX / scalar, mY / scalar, mZ / scalar, mW / scalar));
}

float	Vector4D::dot(const Vector4D& b) const
{
	return ((mX * b.mX) + (mY * b.mY) + (mZ * b.mZ) + (mW * b.mW));
}

float	Vector4D::length()const
{
	return sqrtf(dot(*this));
}

Vector4D	Vector4D::normalize() const
{
	return (*this / length());
}

Vector4D	Vector4D::cross(const Vector4D& b) const
{
	const float mX = mY * b.mZ - mZ * b.mY;
	const float mY = mZ * b.mX - mX * b.mZ;
	const float mZ = mX * b.mY - mY * b.mX;
	return Vector4D(mX, mY, mZ);
}

float Vector4D::getX()
{
	return mX;
}


float Vector4D::getY()
{
	return mY;
}


float Vector4D::getZ()
{
	return 0.0f;
}

float Vector4D::getW()
{
	return 0.0f;
}

float Vector4D::setX(float x)
{
	return 0.0f;
}

float Vector4D::setY(float y)
{
	return 0.0f;
}

float Vector4D::setZ(float z)
{
	return 0.0f;
}

float Vector4D::setW(float w)
{
	return 0.0f;
}
