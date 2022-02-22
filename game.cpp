#include "game.h"
#include "gamesession.h"
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>
#include "date.h"
#include "logtofile.h"

void Game::setGameItems() {

    if(gameMode == 2){
        gameItems = {
                {1, "rock",     {3, 4}, {2, 5}},
                {2, "paper",    {1, 5}, {3, 4}},
                {3, "scissors", {2, 4}, {1, 5}},
                {4, "lizard",   {2, 5}, {1, 3}},
                {5, "Spock",    {3, 1}, {2, 4}}
        };
    }
//    TODO: add third case for invalid user input
    else {
        gameItems = {
                {1, "rock",     {3}, {2}},
                {2, "paper",    {1}, {3}},
                {3, "scissors", {2}, {1}},
        };

    }

}

void Game::selectGameMode(){
    std::cout << "Select game mode:" << std::endl
              <<"1 for Rock/paper/scissors or " << std::endl
              <<"2 for Rock/paper/scissors/lizard/Spock" << std::endl;
    std::cin >> gameMode;
    setGameItems();
    startGameSession();
};

void Game::startGameSession() {
    GameSession gameSession = GameSession();

    gameSession.started = date::format("%d-%m-%Y %H:%M:%S", std::chrono::system_clock::now());

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

    askForAnotherGame();

}

void Game::askForAnotherGame() {
    std::string anotherGame;
    std::cout << "Do you want to play another game? y/n" << std::endl;
    std::cin >> anotherGame;
    if (anotherGame == "y" || anotherGame == "yes") selectGameMode();
    if (anotherGame == "n" || anotherGame == "no") finishGameSession();
}

void Game::finishGameSession() {
    std::cout << "Thank you for playing.";
}

