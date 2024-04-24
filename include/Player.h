#pragma once
#include <string>

class Player
{
public:
    enum items { null, beer, cigPack, cuffs, mGlass, saw }; // Move enum declaration here
    Player(/* args */);
    Player(int startingHP, items inventory[]);
    ~Player();
    int gainHP(int hpGain);
    int getHP();
    items getItem(int indexChoice);
    void getInventory();
    std::string getName();
    void addItem();
    void removeItem();
    void loseHP(int hpLost); // lost health womp womp
    void printItem(int indexChoice);
    void printItems(); // 0: item 1, 1: item 2: number corresponds to array index


private:
    static const int MINHP = 0;
    static const int MAXHP = 4;
    std::string name;
    int hp;
    items inventory[7];  // Now 'items' is defined before use

};