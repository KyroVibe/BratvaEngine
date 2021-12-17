//
// Created by hunte on 12/10/2021.
//

#include "game_loop.h"

#include <string>
#include <iostream>

#include "Graphics/sprite_renderer.h"
#include "Graphics/sprite.h"
#include "Graphics/shaders.h"

GameLoop::GameLoop() {
    _window = new Window(1000, 750);
}

GameLoop::~GameLoop() {
    delete _window;
}

int GameLoop::Run() {

    GLFWwindow* glfwWindow = _window->get_window();

//	Shader shaders[3] = {
//		{ std::string("Resources/Shaders/geo_vert.glsl"), GL_VERTEX_SHADER },
//		{ std::string("Resources/Shaders/geo_frag.glsl"), GL_FRAGMENT_SHADER },
//		{ std::string("Resources/Shaders/geometry.glsl"), GL_GEOMETRY_SHADER }
//	};
//
//	auto program = new ShaderProgram(3, shaders);

    Vec4 scale = Vec4(5, 1, 1, 1);
    Sprite sprite = Sprite(0, 5, 1, Mat4::make_transform(Vec4(), scale, 0));
	SpriteRenderer::get_instance().init(_window);
	SpriteRenderer::get_instance().handoff_sprite(&sprite);

//    std::cout << "Texture Id: " << ((float*)&sprites)[0] << std::endl;
//    for (int i = 1; i < sizeof(Sprite) / 4; ++i) {
//        float* a = (float*)&sprites;
//        std::cout << i << ": " << a[i] << std::endl;
//    }

//    GLuint sprite_buffer;
//    glGenBuffers(1, &sprite_buffer);
//    glBindBuffer(GL_ARRAY_BUFFER, sprite_buffer);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(SpriteData) * 1, sprites.data, GL_DYNAMIC_DRAW);
//
//    GLint textId_attrib = glGetAttribLocation(program->get_program(), "textureId");
//    GLint row0_attrib = glGetAttribLocation(program->get_program(), "row0");
//    GLint row1_attrib = glGetAttribLocation(program->get_program(), "row1");
//    GLint row2_attrib = glGetAttribLocation(program->get_program(), "row2");
//    GLint row3_attrib = glGetAttribLocation(program->get_program(), "row3");
//
//    glEnableVertexAttribArray(textId_attrib);
//    glEnableVertexAttribArray(row0_attrib);
//    glEnableVertexAttribArray(row1_attrib);
//    glEnableVertexAttribArray(row2_attrib);
//    glEnableVertexAttribArray(row3_attrib);
//
//    glVertexAttribPointer(textId_attrib, 1, GL_UNSIGNED_INT, GL_FALSE, sizeof(SpriteData), (void*)(sizeof(float) * 0));
//    glVertexAttribPointer(row0_attrib, 4, GL_FLOAT, GL_FALSE, sizeof(SpriteData), (void*)(sizeof(float) * 1));
//    glVertexAttribPointer(row1_attrib, 4, GL_FLOAT, GL_FALSE, sizeof(SpriteData), (void*)(sizeof(float) * 5));
//    glVertexAttribPointer(row2_attrib, 4, GL_FLOAT, GL_FALSE, sizeof(SpriteData), (void*)(sizeof(float) * 9));
//    glVertexAttribPointer(row3_attrib, 4, GL_FLOAT, GL_FALSE, sizeof(SpriteData), (void*)(sizeof(float) * 13));
//
//    float aspect_ratio = ((float)_window->get_width()) / ((float)_window->get_height());
//    float camera_size = 1.0f / 10.0f;
//    float camera_mat[16] = {
//            camera_size, 0,                          0, 0,
//            0,           aspect_ratio * camera_size, 0, 0,
//            0,           0,                          1, 0,
//            0,           0,                          0, 1
//    };
//    GLint camera_uni = glGetUniformLocation(program->get_program(), "camera");

	float modifier = 0.01f;
	float scale_factor = 5.0f;
    float theta = 0.0f;
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(glfwWindow))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

		if (scale_factor + modifier > 5.0f || scale_factor + modifier < 1.0f)
			modifier *= -1;
		// scale_factor += modifier;
		theta += 1;
		sprite.set_transform(Transform(Vec4(), scale, theta));
		SpriteRenderer::get_instance().render();

//        theta += 1.0f;
//        sprites.set_transform(Mat4::make_transform(Vec4(), Vec4(4, 3, 1, 1), theta));
//        glBufferData(GL_ARRAY_BUFFER, sizeof(SpriteData) * 1, sprites.data, GL_DYNAMIC_DRAW);
//
//        glUseProgram(program->get_program());
//        glUniformMatrix4fv(camera_uni, 1, GL_FALSE, camera_mat);
//        glDrawArrays(GL_POINTS, 0, 1);

        /* Swap front and back buffers */
        glfwSwapBuffers(glfwWindow);

        /* Poll for and process events */
        glfwPollEvents();
    }



//    glDisableVertexArrayAttrib(sprite_buffer, textId_attrib);
//    glDisableVertexArrayAttrib(sprite_buffer, row0_attrib);
//    glDisableVertexArrayAttrib(sprite_buffer, row1_attrib);
//    glDisableVertexArrayAttrib(sprite_buffer, row2_attrib);
//    glDisableVertexArrayAttrib(sprite_buffer, row3_attrib);
//    glDeleteBuffers(1, &sprite_buffer);

    // delete[] sprites;
    // delete program;

    return 0;
}
