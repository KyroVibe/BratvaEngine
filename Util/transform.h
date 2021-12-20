//
// Created by hunte on 12/10/2021.
//

#ifndef IGETIT_TRANSFORM_H
#define IGETIT_TRANSFORM_H

#include "Mat4.h"

class Transform {
public:
    Mat4 transformation;

    Transform();
    Transform(Mat4 t);
    Transform(Vec4 p, Vec4 s, float r);
    ~Transform();

    void set_position(Vec4 p);
    void set_scale(Vec4 s);
    void set_rotation(float r);

    Vec4 get_position();
    Vec4 get_scale();
    float get_rotation();
};

#endif //IGETIT_TRANSFORM_H
