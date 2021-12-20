//
// Created by hunte on 12/19/2021.
//

#ifndef IGETIT_UTIL_MAT4_H_
#define IGETIT_UTIL_MAT4_H_

#include <cmath>

class Vec4 {
 public:
	float x, y, z, w;

	Vec4(): x(0.0), y(0.0), z(0.0), w(1.0) {}
	Vec4(float x_, float y_, float z_);
	Vec4(float x_, float y_, float z_, float w_);
	~Vec4() {}
};

class Mat4 {
 public:
	float data[16];

	Mat4();
	~Mat4();

	void set(int row, int column, float value);
	float get(int row, int column);

	// static Mat4 MakeTransform(float x, float y, float rotation);
	static Mat4 make_transform(Vec4 position, Vec4 scale, float rotation);
};

#endif //IGETIT_UTIL_MAT4_H_
