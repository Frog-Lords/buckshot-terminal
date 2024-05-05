#include "../include/Player.h"
#include <iostream>
#include <string>
// Constructor
Player::Player() {
    // Initialize inventory with 'null' items
    for(int i = 0; i < 8; ++i) {
        inventory[i] = null;
    }
    hp = 5;
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
    for (int i = 0; i < 8; i++)
    {
        inventory[i] = startingInventory[i];
    }
    
}
// Destructor
Player::~Player() {
   std::cout<<"This Player Has Died Game Over";
}

int Player::gainHP(unsigned int hpGain){
    hp += hpGain;
    if(hp > MAXHP){
        hp = MAXHP;
    }
    return 0;
}

int Player::getHP(){
    return hp;
}

Player::items Player::getItem(int index) {
    if (index >= 0 && index < 8) {  // Check if index is within the valid range
        return inventory[index];
    } else {
        return null;  // Return null' if the index is invalid
    }
}


std::string Player::getName(){
    return name;
}

// Lose HP
void Player::loseHP(unsigned int hpLost) {
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
            default: std::cout << " "; break;
        }
        std::cout << std::endl;
}
// Print items in inventory
void Player::printItems() {
    std::cout << std::endl;
    for(int i = 0; i < 8; ++i) {
        std::cout << i + 1 << ": ";
        switch(inventory[i]) {
            case beer: std::cout << "Beer (eject the current round)"; break;
            case cigPack: std::cout << "Cigarette Pack (restore 1 charge)"; break;
            case cuffs: std::cout << "Handcuffs (skip the dealer's next turn)"; break;
            case mGlass: std::cout << "Magnifying Glass (look at the current round)"; break;
            case saw: std::cout << "Hand Saw (the next live round will deal 2 damage)"; break;
            default: std::cout << " "; break;
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