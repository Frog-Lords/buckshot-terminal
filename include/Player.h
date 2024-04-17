#pragma once
class Player
{
private:
    static const int MINHP = 0;
    static const int MAXHP = 4;
    enum items{null, beer, cigPack, cuffs, mGlass, saw};

    int hp;
    items inventory[7];

public:
    Player(/* args */);
    Player(int startingHP, items inventory[]);
    ~Player();
    int gainHP(int hpGain);
    int getHP();
    void loseHP(int hpLost); //lost health womp womp
    void printItem(int indexChoice);
    void printItems(); //0: item 1, 1: item 2: number corresponds to array index
    int promptItem();
    void shootPlayer(Player& target); //shoot other Player by reference of their object
    void shootSelf(); //self harm not endorsed but thats the name of the game
    int useItem(int indexChoice); //inventory [index] gives corresponding item provides prompt are you sure yes/no


};
/*
Beer: ejects shell
cigPack: Restore 1HP
Cuffs: Skip Dealers Turn
mGlass: Lets you peek at shell
saw: Double Damage
*/