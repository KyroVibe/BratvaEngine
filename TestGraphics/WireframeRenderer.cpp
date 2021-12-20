//
// Created by hunte on 12/19/2021.
//

#include "WireframeRenderer.h"
#include "../Util/Mat4.h"

WireframeRenderer::WireframeRenderer() {
	Shader shaders[2] = {
		{ std::string("Resources/Shaders/wireframe_vertex_shader.glsl"), GL_VERTEX_SHADER },
		{ std::string("Resources/Shaders/wireframe_fragment_shader.glsl"), GL_FRAGMENT_SHADER }
	};
	program = new ShaderProgram(2, shaders);

	struct Vertex {
		Vec4 position;
		Vec4 color;
	};

	Vertex vab[3] = {
		{ Vec4( 0.0f,  0.5f, 0.0f, 1.0f), Vec4(0, 1, 0, 1) },
		{ Vec4( 0.5f, -0.5f, 0.0f, 1.0f), Vec4(1, 0, 0, 1) },
		{ Vec4(-0.5f, -0.5f, 0.0f, 1.0f), Vec4(0, 0, 1, 1) }
	};
	unsigned int ib[6] = {
		0, 1, 1, 2, 2, 0
	};

	glGenBuffers(1, &v_buf);
	glBindBuffer(GL_ARRAY_BUFFER, v_buf);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * 3, vab, GL_STATIC_DRAW);

	glGenBuffers(1, &i_buf);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, i_buf);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * 6, ib, GL_STATIC_DRAW);

	a_position = glGetAttribLocation(program->get_program(), "a_position");
	a_color = glGetAttribLocation(program->get_program(), "a_color");

	glEnableVertexAttribArray(a_position);
	glEnableVertexAttribArray(a_color);

	glVertexAttribPointer(a_position, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
	glVertexAttribPointer(a_color, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(sizeof(Vec4)));

}

WireframeRenderer::~WireframeRenderer() {
	glDisableVertexAttribArray(a_position);
	glDisableVertexAttribArray(a_color);

	glDeleteBuffers(1, &v_buf);
	glDeleteBuffers(1, &i_buf);
}

void WireframeRenderer::render() {
	// glPointSize(5);
	glLineWidth(2);
	glUseProgram(program->get_program());
	// glDrawArrays(GL_POINTS, 0, 3);
	glDrawElements(GL_LINES, 6, GL_UNSIGNED_INT, 0);
}
