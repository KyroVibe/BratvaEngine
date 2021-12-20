//
// Created by hunte on 12/18/2021.
//

#ifndef IGETIT_INPUT_MOUSE_H_
#define IGETIT_INPUT_MOUSE_H_

#include "../window.h"

class Mouse {
 private:
	float x_pos = 0;
	float y_pos = 0;

	Mouse() { }
	~Mouse();
 public:
	void init(Window* window);

	static Mouse& get_instance() {
		static Mouse m;
		return m;
	}

	void cursor_position_callback(GLFWwindow* window, double xPos, double yPos);
};

#endif //IGETIT_INPUT_MOUSE_H_
