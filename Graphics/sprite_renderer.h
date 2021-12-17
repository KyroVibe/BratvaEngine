//
// Created by hunte on 12/12/2021.
//

#ifndef IGETIT_SPRITE_RENDERER_H
#define IGETIT_SPRITE_RENDERER_H

#include <map>

#include "sprite.h"
#include "shaders.h"
#include "../Util/camera.h"

class SpriteRenderer {
private:
    SpriteRenderer();
    ~SpriteRenderer();

    std::vector<const Sprite*> sprite_reg; // Might want to move this into some kind of inner or static class within Sprite

    unsigned int buffer;

    VertexAttributes attributes;
	ShaderProgram* program;
	Camera* camera;

public:
	static SpriteRenderer& get_instance() {
		static SpriteRenderer instance;
		return instance;
	}

	void init(Window* window) {
		camera = new Camera(1.0f / 10.0f, ((float)window->get_width()) / ((float)window->get_height()));
	}

    void handoff_sprite(const Sprite* s);
    void render();
    void create_buffer();
    void delete_buffer();
};


#endif //IGETIT_SPRITE_RENDERER_H
