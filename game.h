#ifndef ROCKPAPERSCISSORS_GAME_H
#define ROCKPAPERSCISSORS_GAME_H

#include <iostream>
#include <vector>
#include "item.h"

class Game {
    std::vector<Item> gameItems;
public :
    Game(std::vector<Item> gameItems);

    void start();

    void askForAnotherGame();

    void finish();
};


#endif //ROCKPAPERSCISSORS_GAME_H
