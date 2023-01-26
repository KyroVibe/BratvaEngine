#ifndef _BRATVA_CIRCLE_RENDERER
#define _BRATVA_CIRCLE_RENDERER

#include "../Graphics/shaders.h"

class CircleRenderer {
 private:
	GLuint v_buf, i_buf;
	GLint a_position, a_color;

	ShaderProgram* program;
 public:
	CircleRenderer();
	~CircleRenderer();

	void render();
};

#endif
