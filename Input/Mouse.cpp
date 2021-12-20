//
// Created by hunte on 12/18/2021.
//

#include "Mouse.h"

Mouse::~Mouse() { }

void Mouse::cursor_position_callback(GLFWwindow* window, double xPos, double yPos) {

}

void Mouse::init(Window* window) {
	auto fun = [](GLFWwindow* w, double x, double y) {
		Mouse::get_instance().cursor_position_callback(w, x, y);
	};
	glfwSetCursorPosCallback(window->get_window(), fun);
}
