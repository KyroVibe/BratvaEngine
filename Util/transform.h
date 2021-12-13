//
// Created by hunte on 12/10/2021.
//

#ifndef IGETIT_TRANSFORM_H
#define IGETIT_TRANSFORM_H

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
