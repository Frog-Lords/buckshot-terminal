#include "../include/Player.h"
#include <iostream>

// Constructor
Player::Player() : hp(MAXHP) {
    // Initialize inventory with 'null' items
    for(int i = 0; i < 7; ++i) {
        inventory[i] = null;
    }
    hp = 2;
}

// Destructor
Player::~Player() {
   std::cout<<"womp";
}

// Implement shooting another Player
void Player::shootPlayer(Player& target) {
    // Example: Reduce target's HP by 1
    target.loseHP(1);
}

// Implement shooting oneself
void Player::shootSelf() {
    // Reduce own HP by 1
    loseHP(1);
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

// Use an item from the inventory
void Player::useItem(int indexChoice) {
    if(indexChoice < 0 || indexChoice >= 7) {
        std::cout << "Invalid index." << std::endl;
        return;
    }

    // Implement the logic for using an item here
    // For now, just a placeholder response
    std::cout << "Are you sure you want to use this item? (yes/no)" << std::endl;
}

// Lose HP
void Player::loseHP(int hpLost) {
    hp -= hpLost;
    if(hp < MINHP) hp = MINHP;
}
