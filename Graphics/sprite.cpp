//
// Created by hunte on 12/10/2021.
//

#include "sprite.h"

Sprite::Sprite() { }
Sprite::Sprite(unsigned int t_id) {
    data = new SpriteData { t_id, Transform() };
}
Sprite::Sprite(Mat4 transform_) {
    data = new SpriteData { 0, Transform(transform_) };
}
Sprite::Sprite(unsigned int t_id, Mat4 transform_) {
    data = new SpriteData { t_id, Transform(transform_) };
}
Sprite::~Sprite() {
    delete data;
}
