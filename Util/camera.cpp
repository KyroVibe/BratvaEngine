//
// Created by hunte on 12/15/2021.
//

#include "camera.h"

Camera::Camera() {
	set_size(1.0 / 10.0);
	set_aspect_ratio(16.0f / 9.0f);
}

Camera::Camera(float s, float ar) {
	set_size(s);
	set_aspect_ratio(ar);
}
