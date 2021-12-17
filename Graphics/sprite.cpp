//
// Created by hunte on 12/10/2021.
//

#include "sprite.h"

Sprite::Sprite() {
    data = new SpriteData { 0, 1, 1, Transform() };
}
Sprite::Sprite(unsigned int t_id) {
    data = new SpriteData { t_id, 1, 1, Transform() };
}
Sprite::Sprite(const Mat4& transform_) {
    data = new SpriteData { 0, 1, 1, Transform(transform_) };
}
Sprite::Sprite(unsigned int t_id, const Mat4& transform_) {
    data = new SpriteData { t_id, 1, 1, Transform(transform_) };
}
Sprite::Sprite(unsigned int t_id, float x_t, float y_t, const Mat4& transform_) {
	data = new SpriteData { t_id, x_t, y_t, Transform(transform_) };
}
Sprite::~Sprite() {
    delete data;
}
