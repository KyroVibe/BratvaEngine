//
// Created by hunte on 12/19/2021.
//

#ifndef IGETIT__DATA_H_
#define IGETIT__DATA_H_

#include "Util/Mat4.h"

class Mesh {
 private:
	int _vertex_count;
	Vec4* _vertices;
	int _index_count;
	unsigned int* _indices;

	Mesh(int v_count, Vec4* v, int i_count, unsigned int* i);
	~Mesh();
 public:
	static Mesh* ReadFromFile(const char* path);
};

#endif //IGETIT__DATA_H_
