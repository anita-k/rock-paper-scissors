#ifndef ROCKPAPERSCISSORS_ITEM_H
#define ROCKPAPERSCISSORS_ITEM_H

#include <iostream>
#include <array>

template<class T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &vector) {
    for (const T &value: vector) {
        os << value << ' ';
    }
    return os;
};

struct Item {
    int ID;
    std::string Name;
    std::vector<int> beats;
    std::vector<int> loses;

    friend std::ostream &operator<<(std::ostream &os, const Item &item) {
        os << "ID:" << item.ID << "Name: " << item.Name << " Beats: " << item.beats << " Loses: " << item.loses;
        return os;
    }
};

#endif //ROCKPAPERSCISSORS_ITEM_H
