//
// Created by hunte on 12/10/2021.
//

#ifndef IGETIT_GAME_LOOP_H
#define IGETIT_GAME_LOOP_H

#include "window.h"

class GameLoop {
private:
    Window* _window;
public:
    GameLoop();
    ~GameLoop();

    int Run();
};


#endif //IGETIT_GAME_LOOP_H
