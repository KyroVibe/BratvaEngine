//
// Created by hunte on 12/10/2021.
//

#include "game_loop.h"

#include <string>
#include <iostream>

#include "Graphics/sprite_renderer.h"
#include "Graphics/sprite.h"
#include "Graphics/shaders.h"
#include "data.h"

#include "TestGraphics/WireframeRenderer.h"
#include "gpu_compute.h"

GameLoop::GameLoop() {
    _window = new Window(1280, 720);
}

GameLoop::~GameLoop() {
    delete _window;
}

int GameLoop::Run() {

	// Mesh::ReadFromFile("C:\\Users\\hunte\\unity\\OperationGhostStories\\Assets\\FinalBaseMesh.obj");

    GLFWwindow* glfwWindow = _window->get_window();

	WireframeRenderer* r = new WireframeRenderer();
	// ComputeShaderTest* test = new ComputeShaderTest();
	// delete test;

//    Vec4 scale = Vec4(5, 1, 1, 1);
//    Sprite sprite = Sprite(0, 5, 1, Mat4::make_transform(Vec4(), scale, 0));
//	SpriteRenderer::get_instance().init(_window);
//	SpriteRenderer::get_instance().handoff_sprite(&sprite);

	float modifier = 0.01f;
	float scale_factor = 5.0f;
    float theta = 0.0f;
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(glfwWindow))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

		// test->test();

		r->render();

//		if (scale_factor + modifier > 5.0f || scale_factor + modifier < 1.0f)
//			modifier *= -1;
//		// scale_factor += modifier;
//		theta += 1;
//		sprite.set_transform(Transform(Vec4(), scale, theta));
//		SpriteRenderer::get_instance().render();

        /* Swap front and back buffers */
        glfwSwapBuffers(glfwWindow);

        /* Poll for and process events */
        glfwPollEvents();
    }

	delete r;

    return 0;
}
