//
// Created by hunte on 12/10/2021.
//

#include "transform.h"

#include <cmath>

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
    mat.set(0, 0, scale.y * cos(rotation));
    mat.set(0, 1, scale.x * sin(rotation));
    mat.set(1, 0, scale.y * -sin(rotation));
    mat.set(1, 1, scale.x * cos(rotation));
    // Offset
    mat.set(3, 0, position.x);
    mat.set(3, 1, position.y);
    mat.set(3, 2, position.z);
    mat.set(3, 3, position.w);

    return mat;
}

Transform::Transform() { }
Transform::Transform(Mat4 t) {
    transformation = t;
}
Transform::Transform(Vec4 p, Vec4 s, float r) {
    transformation = Mat4::make_transform(p, s, r);
}

Transform::~Transform() { }

Vec4 Transform::get_scale() {
    return Vec4(
            sqrtf(
                    transformation.get(0, 1) * transformation.get(0, 1)
                    + transformation.get(1, 1) * transformation.get(1, 1)
                    ),
            sqrtf(
                    transformation.get(0, 0) * transformation.get(0, 0)
                    + transformation.get(1, 0) * transformation.get(1, 0)
                ),
                1,
                1
            );
}

float Transform::get_rotation() {
    return (atan2f(-transformation.get(1, 0), transformation.get(0, 0)) / 3.14159f) * 180.0f;
}
