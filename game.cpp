#include "game.h"
#include "gamesession.h"
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>
#include "date.h"
#include "logtofile.h"
#include <xdevapi.h>

Game::Game(std::vector<Item> gameItems) {
    this->gameItems = gameItems;
}

void Game::start() {
    GameSession gameSession = GameSession();
//    auto t = std::time(nullptr);
//    auto tm = *std::localtime(&t);
    gameSession.started = date::format("%d-%m-%Y %H:%M:%S", std::chrono::system_clock::now());
//            std::put_time(&tm, "%d-%m-%Y %H-%M-%S");
    std::cout << gameSession.started << std::endl;


    int userPick = 0;
    std::cout << "Select one:" << std::endl;

    std::vector<Item>::size_type gameItemsSize = gameItems.size();
    for (int i = 0; i < gameItemsSize; i++) {
        std::cout << i + 1 << ": " << gameItems[i].Name << std::endl;
    }

    std::cin >> userPick;
    int gameItemsCount = static_cast<int>(gameItemsSize);
    int cpuPick = (rand() % gameItemsCount) + 1;
    if (userPick > gameItemsCount || userPick < 1) {
        std::cout << "Please make a valid choice." << std::endl;
    }
    Item userPickItem = gameItems[userPick - 1];
    std::cout << "You picked: " << userPickItem.Name << std::endl;
    Item cpuPickItem = gameItems[cpuPick - 1];
    std::cout << "The computer picked: " << cpuPickItem.Name << std::endl;

    std::string result;
    if (userPick == cpuPick) {
        std::cout << "It's a draw." << std::endl;
        result = "Draw";
    } else {

        bool userIsWinner = false;
        for (int ItemID: userPickItem.beats) {
            if (cpuPickItem.ID == ItemID) {
                userIsWinner = true;
                break;
            }
        }

        if (userIsWinner) {
            std::cout << "You Win!" << std::endl;
            result = "Win";
        } else {
            std::cout << "You Lose!" << std::endl;
            result = "Lose";
        }
    }

    gameSession.result = result;

    gameSession.userPickName = userPickItem.Name;
    gameSession.cpuPickName = cpuPickItem.Name;
    gameSession.finished = date::format("%d-%m-%Y %H:%M:%S", std::chrono::system_clock::now());


    std::string gameSessionString = gameSession.toString();

    write_log_file(gameSessionString);
//    std::cout << gameSession << std::endl;

    askForAnotherGame();

}

void Game::askForAnotherGame() {
    std::string anotherGame;
    std::cout << "Do you want to play another game? y/n" << std::endl;
    std::cin >> anotherGame;
    if (anotherGame == "y" || anotherGame == "yes") start();
    if (anotherGame == "n" || anotherGame == "no") finish();
}

void Game::finish() {
    std::cout << "Thank you for playing.";
}

