#include <iostream>
#include <array>

#include "game_loop.h"
#include "Graphics/sprite.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    std::cout << "Size of Sprite: " << sizeof(Sprite) << std::endl;

    GameLoop gl;
    gl.Run();

    return 0;
}
