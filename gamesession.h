#ifndef ROCKPAPERSCISSORS_GAMESESSION_H
#define ROCKPAPERSCISSORS_GAMESESSION_H
#include <iostream>
#include <chrono>
#include <ctime>

class GameSession {
public:
    std::string started;
    std::string finished;
    std::string userPickName;
    std::string cpuPickName;
    std::string result;

    std::string toString() const{
        return "Started: " + started + " | Finished: " + finished + " | User pick: "
           + userPickName + " | Computer Pick: " + cpuPickName + " | Result: " + result;
    }

    friend std::ostream &operator<<(std::ostream &os, const GameSession &session) {
        os << session.toString();
        return os;
    }
};



#endif //ROCKPAPERSCISSORS_GAMESESSION_H
