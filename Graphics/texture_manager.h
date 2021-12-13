//
// Created by hunte on 12/10/2021.
//

#ifndef IGETIT_TEXTURE_MANAGER_H
#define IGETIT_TEXTURE_MANAGER_H

#include <vector>

#include "texture.h"

class TextureMan {
private:
    static TextureMan instance;
    TextureMan();
    ~TextureMan();
public:
    std::vector<Texture*> texture_reg;
    static TextureMan& get_instance() { return TextureMan::instance; }

    unsigned int register_texture(Texture* t) {
        int id = texture_reg.size();
        texture_reg.push_back(t);
        return id;
    }


};


#endif //IGETIT_TEXTURE_MANAGER_H
