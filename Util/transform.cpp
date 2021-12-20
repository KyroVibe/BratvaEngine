//
// Created by hunte on 12/10/2021.
//

#include "transform.h"

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
