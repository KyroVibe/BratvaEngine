//
// Created by hunte on 12/10/2021.
//

#ifndef IGETIT_SHADERS_H
#define IGETIT_SHADERS_H

#include "../window.h"

#include <string>
#include <vector>

struct Shader {
    std::string file;
    GLenum shader_type;
};

class ShaderProgram {
private:
    GLuint program;
public:
    ShaderProgram(int num_shaders, Shader* shaders);
    ~ShaderProgram();

    inline GLuint get_program() { return program; }

    // static ShaderProgram* FromFiles(int num_shaders, Shader* shaders);
};

struct AttributePointer {
public:
    std::string attribute_name;
    int size;
    GLenum type;
    void* offset;
};

class VertexAttributes {
public:
    size_t stride;
    std::vector<AttributePointer> pointers;
    std::vector<unsigned int> indexes;

	VertexAttributes() { }
    VertexAttributes(size_t stri, std::vector<AttributePointer> ptrs);
    ~VertexAttributes();

    void enable();
    void disable();
    void init(ShaderProgram* program);
};

#endif //IGETIT_SHADERS_H
