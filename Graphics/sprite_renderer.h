//
// Created by hunte on 12/12/2021.
//

#ifndef IGETIT_SPRITE_RENDERER_H
#define IGETIT_SPRITE_RENDERER_H

#include <map>

#include "sprite.h"
#include "shaders.h"

class SpriteRenderer {
private:
    static SpriteRenderer _instance;
    SpriteRenderer();
    ~SpriteRenderer();

    std::vector<const Sprite*> sprite_reg; // Might want to move this into some kind of inner or static class within Sprite
public:
    inline SpriteRenderer& get_instance() { return _instance; }

    void handoff_sprite(const Sprite* s);
};


#endif //IGETIT_SPRITE_RENDERER_H
