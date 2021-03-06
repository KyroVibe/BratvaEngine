//
// Created by hunte on 12/10/2021.
//

#include "window.h"

#include <iostream>

Window::Window(int width, int height) {

    _width = width;
    _height = height;

    /* Initialize the library */
    if (!glfwInit())
        return;

    /* Create a windowed mode window and its OpenGL context */
    _window = glfwCreateWindow(width, height, "Hey Cunt, is it working yet?", NULL, NULL);
    if (!_window) {
        glfwTerminate();
        return;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(_window);

    GLenum glewResult = glewInit();
    if (glewResult != GLEW_OK) {
        std::cout << glewGetErrorString(glewResult) << std::endl;
        glfwTerminate();
        return;
    }
}

Window::~Window() {
    glfwTerminate();
}
