//
// Created by hunte on 12/19/2021.
//

#ifndef IGETIT__GPU_COMPUTE_H_
#define IGETIT__GPU_COMPUTE_H_

#include "Graphics/shaders.h"
#include "Util/Mat4.h"

class ComputeShaderTest {
 private:
	Vec4* colors;

	GLuint ssbo;
	ShaderProgram* compute_shader;
	ShaderProgram* render_shader;
 public:
	ComputeShaderTest();
 	~ComputeShaderTest();

	 void test();
};

#endif //IGETIT__GPU_COMPUTE_H_
