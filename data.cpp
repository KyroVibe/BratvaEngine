//
// Created by hunte on 12/19/2021.
//

#include "data.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

Mesh::Mesh(int v_count, Vec4* v, int i_count, unsigned int* i) {
	_vertex_count = v_count;
	_vertices = v;
	_index_count = i_count;
	_indices = i;
}

Mesh::~Mesh() {
	delete _vertices;
	delete _indices;
}

Mesh* Mesh::ReadFromFile(const char* path) {

	std::ifstream vert_file;
	vert_file.open(path, std::ifstream::in);

	std::vector<Vec4> vertices;
	std::vector<unsigned int> indices;

	std::vector<std::string> lines;

	std::string contents;
	char c;
	while (vert_file.get(c)) {
		contents.push_back(c);
	}

	size_t pos = 0;
	while (true) {
		pos = contents.find('\n');
		if (pos == std::string::npos)
			break;
		lines.push_back(contents.substr(0, pos));
		contents.erase(0, pos + 1);
	}

//	char* c_str = new char[contents.size() + 1]; // Not really the size because debug bs but it's whatever
//	contents.copy(c_str, contents.size(), 0);
//	c_str[contents.size()] = '\0';
	vert_file.close();

	return nullptr;
}
