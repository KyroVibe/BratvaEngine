//
// Created by hunte on 12/15/2021.
//

#ifndef IGETIT_UTIL_CAMERA_H_
#define IGETIT_UTIL_CAMERA_H_

#include "transform.h"

class Camera {
 private:
	Mat4 mat;
 public:
	Camera();
	Camera(float s, float ar);
	~Camera() { }

	inline Mat4* get_mat() { return &mat; }
	inline float get_size() { return mat.get(0, 0); }
	inline float get_aspect_ratio() { return mat.get(1, 1) / mat.get(0, 0); }
	void set_size(float s) {
		mat.set(1, 1, get_aspect_ratio() * s);
		mat.set(0, 0, s);
	}
	void set_aspect_ratio(float ar) {
		mat.set(1, 1, get_size() * ar);
	}
};

#endif //IGETIT_UTIL_CAMERA_H_
