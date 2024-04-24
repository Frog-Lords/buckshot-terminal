#include "../include/Player.h"
#include <iostream>
#include <string>
// Constructor
Player::Player() {
    // Initialize inventory with 'null' items
    for(int i = 0; i < 7; ++i) {
        inventory[i] = null;
    }
    hp = 4;
}

Player::Player(int startingHP, items startingInventory[]){
    if(startingHP>MAXHP){
        startingHP=MAXHP;
    }
    else if (startingHP<MINHP)
    {
        startingHP=MINHP;
    }
    
    hp=startingHP;
    for (int i = 0; i < 7; i++)
    {
        inventory[i] = startingInventory[i];
    }
    
}
// Destructor
Player::~Player() {
   std::cout<<"womp";
}

int Player::gainHP(int hpGain){
    hp += hpGain;
    if(hp>MAXHP){
        hp = MAXHP;
    }
    return 0;
}

int Player::getHP(){
    return hp;
}

Player::items Player::getItem(int index) {
    if (index >= 0 && index < 7) {  // Check if index is within the valid range
        return inventory[index];
    } else {
        return null;  // Return null' if the index is invalid
    }
}


std::string Player::getName(){
    return name;
}

// Lose HP
void Player::loseHP(int hpLost) {
    hp -= hpLost;
    if(hp < MINHP) hp = MINHP;
}

void Player::printItem(int indexChoice) {
        switch(inventory[indexChoice]) {
            case beer: std::cout << "Beer"; break;
            case cigPack: std::cout << "Cigarette Pack"; break;
            case cuffs: std::cout << "Handcuffs"; break;
            case mGlass: std::cout << "Magnifying Glass"; break;
            case saw: std::cout << "Hand Saw"; break;
            default: std::cout << "Empty"; break;
        }
        std::cout << std::endl;
}
// Print items in inventory
void Player::printItems() {
    for(int i = 0; i < 7; ++i) {
        std::cout << i << ": ";
        switch(inventory[i]) {
            case beer: std::cout << "Beer"; break;
            case cigPack: std::cout << "Cigarette Pack"; break;
            case cuffs: std::cout << "Handcuffs"; break;
            case mGlass: std::cout << "Magnifying Glass"; break;
            case saw: std::cout << "Hand Saw"; break;
            default: std::cout << "Empty"; break;
        }
        std::cout << std::endl;
    }
}


/*
Beer: ejects shell
cigPack: Restore 1HP
Cuffs: Skip Dealers Turn
mGlass: Lets you peek at shell
saw: Double Damage
*/