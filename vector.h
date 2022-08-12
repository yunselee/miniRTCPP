
#include <cmath>

class vec4 final
{
	vec4();
	vec4(float x, float y, float z);
	vec4(float x, float y, float z, float w);

	vec4	normalize() const;
	vec4	operator+(const vec4 &b) const;
	vec4	operator-(const vec4 &b) const ;
	vec4	operator*(float scalar) const;
	vec4	operator/(float scalar) const;
	float	size()const;

	float	dot(const vec4 &b) const ;
	vec4	cross(const vec4 &b) const

private:	
	float	mX;
	float	mY;
	float	mZ;
	float	mW;	
};


vec4::vec4() : mX(0), mY(0), mZ(0), mW(0)
{}
vec4::vec4(float x, float y, float z) : mX(x), mY(y), mZ(z), mW(0)
{}
vec4::vec4(float x, float y, float z, float w) : mX(x), mY(y), mZ(z), mW(w)
{}

vec4	vec4::operator+(const vec4 &b) const
{
	return (vec4(mX + b.mX, mY + b.mY, mZ + b.mZ, mW + b.mW));
}

vec4	vec4::operator-(const vec4 &b) const
{
	return (vec4(mX - b.mX, mY - b.mY, mZ - b.mZ, mW - b.mW));
}

vec4	vec4::operator*(float scalar) const
{
	return (vec4(mX * scalar, mY * scalar, mZ * scalar, mW * scalar));
}

vec4	vec4::operator/(float scalar) const
{
	return (vec4(mX / scalar, mY / scalar, mZ / scalar, mW / scalar));
}

float	vec4::dot(const vec4 &b) const
{
	return ((mX * b.mX) + (mY * b.mY) + (mZ * b.mZ) + (mW * b.mW));
}

float	vec4::size()const
{
	return sqrtf(dot(*this));
}

vec4	vec4::normalize() const
{
	return (*this / size());
}

vec4	vec4::cross(const vec4 &b) const
{
	const float x = mY * b.mZ - mZ * b.mY;
	const float y = mZ * b.mX - mX * b.mZ;
	const float z = mX * b.mY - a.y * b.mX;
	return vec4(x, y ,z);
}
