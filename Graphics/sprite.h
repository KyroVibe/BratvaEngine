//
// Created by hunte on 12/10/2021.
//

#ifndef IGETIT_SPRITE_H
#define IGETIT_SPRITE_H

#include "../Util/transform.h"

struct SpriteData {
    unsigned int texture_id;
    Transform transform;
};

class Sprite {
public:
    SpriteData* data;

    Sprite();
    Sprite(unsigned int t_id);
    Sprite(Mat4 transform_);
    Sprite(unsigned int t_id, Mat4 transform_);
    ~Sprite();
};

#endif //IGETIT_SPRITE_H
