#pragma once
class Vector4D
{
public:
	Vector4D();
	Vector4D(float mX, float mY, float mZ);
	Vector4D(float mX, float mY, float mZ, float mW);

	Vector4D	normalize() const;
	Vector4D	operator+(const Vector4D& b) const;
	Vector4D	operator-(const Vector4D& b) const;
	Vector4D	operator*(float scalar) const;
	Vector4D	operator/(float scalar) const;
	float	length()const;

	float	dot(const Vector4D& b) const;
	Vector4D	cross(const Vector4D& b) const;

	float getX();
	float getY();
	float getZ();
	float getW();
	float setX(float x);
	float setY(float y);
	float setZ(float z);
	float setW(float w);
private:
	float	mX;
	float	mY;
	float	mZ;
	float	mW;
};

