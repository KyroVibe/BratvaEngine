//
// Created by hunte on 12/10/2021.
//

#include "texture.h"

Texture::Texture(int width_, int height_) {
    width = width_;
    height = height_;

    pixels = new Color[width * height];
}

Texture::~Texture() {
    delete[] pixels;
}
