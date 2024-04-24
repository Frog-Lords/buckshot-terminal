#include <iostream>
#include <iomanip>
#include "../include/Player.h"


void shootPlayer(Player& target); //shoot other Player by reference of their object
int useItem(Player& target, int indexChoice); //inventory [index] gives corresponding item provides prompt are you sure yes/no
void printHealth(Player* targets[], int size);


int main() {
    Player mainPlayer;
    Player enemy;
    static const int TOTAL_PLAYERS = 2;
    Player* players[] = {&mainPlayer, &enemy};
    enemy.loseHP(1);
    printHealth(players, TOTAL_PLAYERS);
    std::cout<<std::endl;
};

void printHealth(Player* targets[], int size){
    for (int i = 0; i < size; i++) {
        Player* player = targets[i];
        int currentHealth = player->getHP();
        std::cout << "Player " << (i + 1) << " Health: ";
        for (int j = 0; j < currentHealth; j++) {
            std::cout << "🗲 ";
        }
        std::cout << std::setw(10);
    }
    std::cout << std::endl;
};

void shootPlayer(Player& target) {
    // Example: Reduce target's HP by 1
    target.loseHP(1);
};


// Use an item from the inventory
int promptItem(Player& target) {
    std::cout << "Please Enter A Number For An Item To Use\n";
    target.printItems();
    int indexChoice;
    std::cin >> indexChoice;
    if (indexChoice < 0 || indexChoice >= 7) {
        std::cout << "Invalid index. Please try again." << std::endl;
        return -1;
    }
    char choice;
    std::cout << "Are you sure you want to use this item? (Y/N)" << std::endl;
    std::cin >> choice;
    choice = std::tolower(choice);

    if (choice == 'y') {
        std::cout << "Confirmed Selected Item ";
        target.printItem(indexChoice);
        return indexChoice;
    } else if (choice == 'n') {
        std::cout << "Chose not to select item." << std::endl;
        return 0;
    } else {
        std::cout << "Invalid selection." << std::endl;
        return -2;
    }
}

int useItem(Player& target, int indexChoice) {
    if (indexChoice < 0 || indexChoice >= 7) {
        std::cout << "Invalid item index.\n";
        return -1;
    }

    Player::items item = target.getItem(indexChoice);  // Assume getItem is updated to handle an index.
    switch (item) {
    case Player::null:
        std::cout << "You tried to use an empty slot.\n";
        break;
    case Player::beer:
        std::cout << "Beer effect not implemented yet.\n";
        break;
    case Player::cigPack:
        target.gainHP(1);
        std::cout << "Gained 1 HP!\n";
        break;
    case Player::cuffs:
        std::cout << "Cuffs effect not implemented yet.\n";
        break;
    case Player::mGlass:
        std::cout << "Future seeing effect not implemented yet.\n";
        break;
    case Player::saw:
        std::cout << "Double damage effect not implemented yet.\n";
        break;
    default:
        std::cout << "Invalid item selection.\n";
        break;
    }
    return 0;
}


/*
Beer: ejects shell
cigPack: Restore 1HP
Cuffs: Skip Dealers Turn
mGlass: Lets you peek at shell
saw: Double Damage
*/