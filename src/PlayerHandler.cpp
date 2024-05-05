#include "../include/PlayerHandler.h"

void PlayerHandler::printHealth(Player* targets[], int size){
    for (int i = 0; i < size; i++) {
        Player* player = targets[i];
        int currentHealth = player->getHP();
        std::cout << "Player " << (i + 1) << " Charges: ";
        for (int j = 0; j < currentHealth; j++) {
            std::cout << "[] ";
        }
        std::cout << std::endl;
    }
    std::cout << std::setw(0);
    std::cout << std::endl;
};

void PlayerHandler::shootPlayer(Player& target, std::stack<int>& shotgun, unsigned int modifier) {
    // Example: Reduce target's HP by 1
    bool isLiveBullet = shotgun.top();
    shotgun.pop();

    if(isLiveBullet == true){
        std::cout << ".";
        sleep(1);
        std::cout << ".";
        sleep(1);
        std::cout << ".";
        sleep(1);
        std::cout << "*BANG*\n";
        target.loseHP(1*modifier);
        sleep(2);
    } else {
        std::cout << ".";
        sleep(1);
        std::cout << ".";
        sleep(1);
        std::cout << ".";
        sleep(1);
        std::cout << "*click*\n";
        sleep(2);
    }
};

// Use an item from the inventory
int PlayerHandler::promptItem(Player& target) {
    std::cout << "Use which item?" << std::endl;
    target.printItems();
    int indexChoice;
    std::cin >> indexChoice;
    if (indexChoice - 1 < 0 || indexChoice - 1 > 7) {
        std::cout << "Invalid choice. Please try again: ";
        return -1;
    }
    char choice;
    std::cout << "Are you sure? (Y/N)" << std::endl;
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

int PlayerHandler::useItem(Player& target, int indexChoice, unsigned int& modifier, std::stack<int> shotgun, bool& isSkipped) {
    bool isLiveBullet;
    if (indexChoice - 1 < 0 || indexChoice - 1 > 7) {
        std::cout << "Invalid item index.\n";
        return -1;
    }

    Player::items item = target.getItem(indexChoice);  // Assume getItem is updated to handle an index.
    switch (item) {
        case Player::null:
        std::cout << "You tried to use an empty slot.\n";
        break;
        
        case Player::beer:
        isLiveBullet = shotgun.top();
        shotgun.pop();
        if (isLiveBullet == true){
            std::cout << "A live shell was ejected.\n";
            break;       
        } else {
            std::cout<<"A blank was ejected\n"; 
        break;
        }
        
        case Player::cigPack:
        target.gainHP(1);
        break;

        case Player::cuffs:
        isSkipped = true;
        break;

        case Player::mGlass:
        isLiveBullet = shotgun.top();
        if(isLiveBullet == true){
            std::cout << "Using the magnifying glass, you see that the current round is live.\n";
            break;
        }
        std::cout<< "Using the magnifying glass, you see that the current round is blank.\n";
        break;

        case Player::saw:
        modifier = 2;
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