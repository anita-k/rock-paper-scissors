#ifndef ROCKPAPERSCISSORS_GAME_H
#define ROCKPAPERSCISSORS_GAME_H

#include <iostream>
#include <vector>
#include "item.h"

class Game {
private:
    std::vector<Item> gameItems;
public:
    int gameMode;

    void selectGameMode();

    void setGameItems();

    void startGameSession();

    void askForAnotherGame();

    void finishGameSession();
};


#endif //ROCKPAPERSCISSORS_GAME_H
