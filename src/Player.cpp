#include "../include/Player.h"
#include <iostream>

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
}
int Player::getHP(){
    return hp;
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



// Use an item from the inventory
int Player::promptItem() {

    std::cout<<"Please Enter A Number For An Item To Use\n";
    printItems();
    int indexChoice;
    std::cin>>indexChoice;
    if(indexChoice < 0 || indexChoice >= 7) {
        std::cout << "Invalid index." << std::endl;
        return -1;
    }
    char choice;
    std::cout << "Are you sure you want to use this item? (y/n)" << std::endl;
    std::cin >> choice;

    if(choice >90){
        choice -= 32; // makes capitals lower case
    }
    switch (choice){
    case 'y':{
        std::cout<<"Confirmed Selected Item ";
        printItem(indexChoice);
        return indexChoice;
    }
    case 'n':{
    std::cout<<"Chose not to select item\n";
    printItem(indexChoice);
    return 0;
    }
    default:{
        std::cout<<"Selected value not allowed\n";
        return -2;
    }
    }

};
int Player::useItem(int indexChoice){
    items item = inventory[indexChoice];
    switch (item)
    {
    case null:{
        std::cout<<"You Tried to Use Nothing Because You Are Nothing\n";
        break;}
    
    case beer:
    std::cout<<"beer not implemented\n";
    break;

    case cigPack:
    gainHP(1);
    std::cout<<"Gained 1 HP!\n";
    break;

    case cuffs:{
        std::cout<<"cuffs are not implemented\n";
        break;
    }
    case mGlass:{
        std::cout<<"SEE THE FUTURE IS NOT IMPLEMENTED\n";
        break;
    }
    case saw:{
        std::cout<<"DOUBLE DAMAGE NOT IMPLEMENTED\n";
        break;
    }
    default:
    std::cout<<"You inputted the wrong number bee yatch";
        break;
    
    return 0;
}
/*
Beer: ejects shell
cigPack: Restore 1HP
Cuffs: Skip Dealers Turn
mGlass: Lets you peek at shell
saw: Double Damage
*/