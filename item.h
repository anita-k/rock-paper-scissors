#ifndef ROCKPAPERSCISSORS_ITEM_H
#define ROCKPAPERSCISSORS_ITEM_H

#include <iostream>
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

#endif //ROCKPAPERSCISSORS_ITEM_H
