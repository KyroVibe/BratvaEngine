//
// Created by hunte on 12/12/2021.
//

#include "sprite_renderer.h"

void SpriteRenderer::handoff_sprite(const Sprite *s) {
    sprite_reg.push_back(s);
}

SpriteRenderer::SpriteRenderer() {

}

SpriteRenderer::~SpriteRenderer() {
    for (auto iter = sprite_reg.begin(); iter != sprite_reg.end(); iter++) {
        delete &iter;
    }
}
