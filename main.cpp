#include <iostream>
#include <vector>
#include <array>


template<class T, std::size_t N>
std::ostream &operator<<(std::ostream &os, const std::array<T, N> &array) {
    for (const T &value: array) {
        os << value << ' ';
    }
    return os;
};

struct Item {
    int ID;
    std::string Name;
    std::array<int, 2> beats;
    std::array<int, 2> loses;

    friend std::ostream &operator<<(std::ostream &os, const Item &item) {
        os << "ID:" << item.ID << "Name: " << item.Name << " Beats: " << item.beats << " Loses: " << item.loses;
        return os;
    }
};


std::vector<Item> getGameItems() {
    std::vector<Item> gameItems = {
//            {"rock",     {"scissors", "lizard"}, {"paper",    "Spock"}},
//            {"paper",    {"rock",     "Spock"},  {"scissors", "lizard"}},
//            {"scissors", {"paper",    "lizard"}, {"rock",     "Spock"}},
//            {"lizard",   {"paper",    "Spock"},  {"rock",     "scissors"}},
//            {"Spock",    {"scissors", "rock"},   {"paper",    "lizard"}}
//    };

            {1, "rock",     {3, 4}, {2, 5}},
            {2, "paper",    {1, 5}, {3, 4}},
            {3, "scissors", {2, 4}, {1, 5}},
            {4, "lizard",   {2, 5}, {1, 3}},
            {5, "Spock",    {3, 1}, {2, 4}}
    };

    return gameItems;
}

void finish_game() {
    std::cout << "Thank you for playing.";
}

void start_game() {
    std::string anotherGame;
    int userPick = 0;
    std::cout << "Select one:" << std::endl;
    std::vector<Item> gameItems = getGameItems();
    std::vector<Item>::size_type gameItemsSize = gameItems.size();
    for (int i = 0; i < gameItemsSize; i++) {
        std::cout << i + 1 << ": " << gameItems[i].Name << std::endl;
    }

    std::cin >> userPick;
    int gameItemsCount = static_cast<int>(gameItemsSize);
    int cpuPick = (rand() % gameItemsCount) + 1;
    if (userPick > gameItemsCount || userPick < 1) {
        std::cout << "Please make a valid choice between 1 and 5." << std::endl;
    }
    if (userPick == cpuPick) std::cout << "It's a draw" << std::endl;
    Item userPickItem = gameItems[userPick - 1];
    std::cout << "You picked: " << userPickItem.Name << std::endl;
    Item cpuPickItem = gameItems[cpuPick - 1];
    std::cout << "The computer picked: " << cpuPickItem.Name << std::endl;

//    userPickItem.beats;
    bool userIsWinner = false;
    for (int ItemID: userPickItem.beats) {
        if (cpuPickItem.ID == ItemID) {
            userIsWinner = true;
            break;
        }
    }
//    std::array::iterator *cpuPickItemNameResult;
//    *cpuPickItemNameResult = std::find(std::begin(userPickItem.beats), std::end(userPickItem.beats), cpuPickItem.Name);

//    if (userPick == 1 && cpuPick == 2) std::cout << "You lose" << std::endl;
//    if (userPick == 1 && cpuPick == 3) std::cout << "You win" << std::endl;
//    if (userPick == 2 && cpuPick == 1) std::cout << "You win" << std::endl;
//    if (userPick == 2 && cpuPick == 3) std::cout << "You lose" << std::endl;
//    if (userPick == 3 && cpuPick == 1) std::cout << "You lose" << std::endl;
//    if (userPick == 3 && cpuPick == 2) std::cout << "You win" << std::endl;

    if (userIsWinner) { std::cout << "You Win!" << std::endl; }
    else { std::cout << "You Lose!" << std::endl; }

    std::cout << "Do you want to play another game? y/n" << std::endl;
    std::cin >> anotherGame;
    if (anotherGame == "y" || anotherGame == "yes") start_game();
    if (anotherGame == "n" || anotherGame == "no") finish_game();

}


int main() {
    start_game();
//    Item item = Item{"rock", {"scissors", "lizard"}, {"paper", "Spock"} };
//    std::cout << item;
    return 0;
}