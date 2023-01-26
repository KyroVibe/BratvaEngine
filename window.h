//
// Created by hunte on 12/10/2021.
//

#ifndef IGETIT_WINDOW_H
#define IGETIT_WINDOW_H

#include "GL/glew.h"
#include <GLFW/glfw3.h>

class Window {
private:
    int _width, _height;
    GLFWwindow* _window;
public:
    Window(int width, int height);
    ~Window();

    inline GLFWwindow* get_window() { return _window; }
    inline int get_width() { return _width; }
    inline int get_height() { return _height; }
};

#endif //IGETIT_WINDOW_H
