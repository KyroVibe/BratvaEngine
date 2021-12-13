//
// Created by hunte on 12/10/2021.
//

#ifndef IGETIT_TEXTURE_H
#define IGETIT_TEXTURE_H

struct Color {
    float r = 1, g = 1, b = 1;
};

class Texture {
public:
    int width, height;
    Color* pixels;

    Texture(int width_, int height_);
    ~Texture();
};

#endif //IGETIT_TEXTURE_H
