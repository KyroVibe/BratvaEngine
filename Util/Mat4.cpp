//
// Created by hunte on 12/19/2021.
//

#include "Mat4.h"

Vec4::Vec4(float x_, float y_, float z_) {
	x = x_;
	y = y_;
	z = z_;
	w = 1;
}

Vec4::Vec4(float x_, float y_, float z_, float w_) {
	x = x_;
	y = y_;
	z = z_;
	w = w_;
}

Mat4::Mat4() {
	// data[16] = { 0 };
	for (int i = 0; i < 16; ++i) {
		if (i % 5 == 0)
			data[i] = 1.0f;
		else
			data[i] = 0.0f; // What the actual hell c++ doing
	}
}

Mat4::~Mat4() { }

void Mat4::set(int row, int column, float value) {
	data[(row * 4) + column] = value;
}

float Mat4::get(int row, int column) {
	return data[(row * 4) + column];
}

//Mat4 Mat4::MakeTransform(float x, float y, float rotation) {
//    return Mat4::MakeTransform({ x, y }, rotation);
//}
Mat4 Mat4::make_transform(Vec4 position, Vec4 scale, float rotation) {

	rotation = (rotation / 180) * 3.14159;

	Mat4 mat;
	// Rotation
	mat.set(0, 0, scale.x * cos(rotation));
	mat.set(0, 1, scale.y * sin(rotation));
	mat.set(1, 0, scale.x * -sin(rotation));
	mat.set(1, 1, scale.y * cos(rotation));
	// Offset
	mat.set(3, 0, position.x);
	mat.set(3, 1, position.y);
	mat.set(3, 2, position.z);
	mat.set(3, 3, position.w);

	return mat;
}
