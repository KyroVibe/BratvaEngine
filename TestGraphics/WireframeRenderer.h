//
// Created by hunte on 12/19/2021.
//

#ifndef IGETIT_TESTGRAPHICS_WIREFRAMERENDERER_H_
#define IGETIT_TESTGRAPHICS_WIREFRAMERENDERER_H_

#include "../Graphics/shaders.h"

class WireframeRenderer {
 private:
	GLuint v_buf, i_buf;
	GLint a_position, a_color;

	ShaderProgram* program;
 public:
	WireframeRenderer();
	~WireframeRenderer();

	void render();
};

#endif //IGETIT_TESTGRAPHICS_WIREFRAMERENDERER_H_
