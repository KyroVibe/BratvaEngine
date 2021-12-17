//
// Created by hunte on 12/10/2021.
//

#ifndef IGETIT_SPRITE_H
#define IGETIT_SPRITE_H

#include "../Util/transform.h"

struct SpriteData {
    unsigned int texture_id;
	float x_tile;
	float y_tile;
    Transform transform;
};

class Sprite {
public:
    SpriteData* data;

    Sprite();
    Sprite(unsigned int t_id);
    Sprite(const Mat4& transform_);
    Sprite(unsigned int t_id, const Mat4& transform_);
	Sprite(unsigned int t_id, float x_t, float y_t, const Mat4& transform_);
    ~Sprite();

    inline Transform& get_transform() { return data->transform; }
    inline unsigned int get_texture_id() { return data->texture_id; }
    inline void set_transform(Transform t) { data->transform = t; }
    inline void set_texture_id(unsigned int t) { data->texture_id = t; }
};

#endif //IGETIT_SPRITE_H
