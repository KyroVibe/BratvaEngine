//
// Created by hunte on 12/12/2021.
//

#include "sprite_renderer.h"

SpriteRenderer::SpriteRenderer() {
	Shader shaders[3] = {
		{ std::string("Resources/Shaders/sprite_vertex_shader.glsl"), GL_VERTEX_SHADER },
		{ std::string("Resources/Shaders/sprite_fragment_shader.glsl"), GL_FRAGMENT_SHADER },
		{ std::string("Resources/Shaders/sprite_geometry_shader.glsl"), GL_GEOMETRY_SHADER }
	};
	program = new ShaderProgram(3, shaders);
	create_buffer();
}

SpriteRenderer::~SpriteRenderer() {

	delete_buffer();

    for (auto iter = sprite_reg.begin(); iter != sprite_reg.end(); iter++) {
        delete &iter;
    }
	delete program;
	delete camera;
}

void SpriteRenderer::create_buffer() {
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    std::vector<AttributePointer> attribute_data;
	attribute_data.push_back({ "textureId", 1, GL_UNSIGNED_INT, 0 });
	attribute_data.push_back({ "tile", 2, GL_FLOAT, (void*)(4 * 1) });
	// attribute_data.push_back({ "yTile", 1, GL_FLOAT, (void*)(4 * 2) });
	attribute_data.push_back({ "row0", 4, GL_FLOAT, (void*)(4 * 3) });
	attribute_data.push_back({ "row1", 4, GL_FLOAT, (void*)(4 * 7) });
	attribute_data.push_back({ "row2", 4, GL_FLOAT, (void*)(4 * 11) });
	attribute_data.push_back({ "row3", 4, GL_FLOAT, (void*)(4 * 15) });
	attributes = VertexAttributes(sizeof(SpriteData), attribute_data);
	attributes.init(program);
}

void SpriteRenderer::delete_buffer() {
    glDeleteBuffers(1, &buffer);
}

void SpriteRenderer::handoff_sprite(const Sprite *s) {
    sprite_reg.push_back(s);
}

void SpriteRenderer::render() {
	attributes.enable();
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	int spritesToRender = sprite_reg.size();
	glBufferData(GL_ARRAY_BUFFER, sizeof(SpriteData) * spritesToRender, NULL, GL_DYNAMIC_DRAW);
	for (int i = 0; i < spritesToRender; i++) {
		glBufferSubData(GL_ARRAY_BUFFER, sizeof(SpriteData) * i, sizeof(SpriteData), sprite_reg.at(i)->data);
	}

	GLint camera_uni = glGetUniformLocation(program->get_program(), "camera");
	glUseProgram(program->get_program());
	glUniformMatrix4fv(camera_uni, 1, GL_FALSE, camera->get_mat()->data);

	glDrawArrays(GL_POINTS, 0, spritesToRender);
	attributes.disable();
}
