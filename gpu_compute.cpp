//
// Created by hunte on 12/19/2021.
//

#include "gpu_compute.h"

#include <stdio.h>

ComputeShaderTest::ComputeShaderTest() {
	Shader shader = { "Resources/Shaders/compute_shader.glsl", GL_COMPUTE_SHADER };
	compute_shader = new ShaderProgram(1, &shader);
	Shader shaders[2] = {
		{ "Resources/Shaders/compute_vertex_shader.glsl", GL_VERTEX_SHADER },
		{ "Resources/Shaders/compute_fragment_shader.glsl", GL_FRAGMENT_SHADER }
	};
	render_shader = new ShaderProgram(2, shaders);
}

ComputeShaderTest::~ComputeShaderTest() {
	delete compute_shader;
	delete render_shader;
}

void ComputeShaderTest::test() {
	colors = new Vec4[16 * 9];

	glGenBuffers(1, &ssbo);
	glBindBuffer(GL_SHADER_STORAGE_BUFFER, ssbo);
	glBufferData(GL_SHADER_STORAGE_BUFFER, sizeof(Vec4) * 16 * 9, colors, GL_DYNAMIC_READ);
	glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 3, ssbo);

	printf("%f, %f, %f\n", colors[143].x, colors[143].y, colors[143].z);
	glUseProgram(compute_shader->get_program());
	glDispatchCompute(16, 9, 1);

	glGetBufferSubData(GL_SHADER_STORAGE_BUFFER, 0, sizeof(Vec4) * 16 * 9, colors);
	// glDeleteBuffers(1, &ssbo);
	// colors = (Vec4*)glMapBuffer(GL_SHADER_STORAGE_BUFFER, GL_READ_WRITE);

	printf("%f, %f, %f\n", colors[143].x, colors[143].y, colors[143].z);

	GLuint tmp;
	glGenBuffers(1, &tmp);
	glBindBuffer(GL_ARRAY_BUFFER, tmp);
	int tmp_data = 69;
	glBufferData(GL_ARRAY_BUFFER, sizeof(int), &tmp_data, GL_STATIC_DRAW);

	glUseProgram(render_shader->get_program());
	glPointSize(2000);
	glDrawArrays(GL_POINTS, 0, 1);

}
