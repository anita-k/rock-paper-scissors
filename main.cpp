#include <iostream>
#include <vector>
#include <array>
#include "item.h"
#include "game.h"

std::vector<Item> getGameItems(int gameMode) {
    std::vector<Item> gameItems;
    if(gameMode == 2){
        gameItems = {
                {1, "rock",     {3, 4}, {2, 5}},
                {2, "paper",    {1, 5}, {3, 4}},
                {3, "scissors", {2, 4}, {1, 5}},
                {4, "lizard",   {2, 5}, {1, 3}},
                {5, "Spock",    {3, 1}, {2, 4}}
        };
    }
    else {
        gameItems = {
                {1, "rock",     {3}, {2}},
                {2, "paper",    {1}, {3}},
                {3, "scissors", {2}, {1}},
        };

    }

    return gameItems;
}

int main() {
    std::cout << "Select game mode:" << std::endl
    <<"1 for Rock/paper/scissors or " << std::endl
    <<"2 for Rock/paper/scissors/lizard/Spock" << std::endl;
    int gameMode;
    std::cin >> gameMode;
    Game game = Game(getGameItems(gameMode));

    game.start();

    return 0;
}
