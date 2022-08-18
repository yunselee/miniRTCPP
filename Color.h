#pragma once
class Color
{
public:
	Color();
	Color(unsigned char r, unsigned char g, unsigned char b);
	unsigned int ToHex() const;
	Color operator+(const Color& a);
	Color operator*(double a);

	//t_color color_disruption(const t_quadrics* Q, t_vec3 point_from_cam, t_color obj_color);
	//t_color get_texture_color(const t_quadrics* Q, const t_xpm* texture, t_vec point);

private:
	unsigned char mAlpha;
	unsigned char mRed;
	unsigned char mGreen;
	unsigned char mBlue;
};

