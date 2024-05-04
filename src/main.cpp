#include "../include/generateShotgun.h"
#include "../include/Player.h"
#include "../include/PlayerHandler.h"
#include "../include/Utils.h"


static const int TOTAL_PLAYERS = 2;

enum gameState { MAIN_MENU, INTRO, PLAYING, WIN_STATE, GAME_OVER };


void runGame();
void mainMenu(Utils util);
void intro(Utils util, std::string& name);
void playingGame();
void playerTurn(Player& player, Player::items pInventory[], Player& dealer, Player::items dInventory[], PlayerHandler& playerActions, unsigned int& damage, std::stack<int>& shotgun, bool& playerSkipped, bool& dealerSkipped);
int chooseAction();
void executeAction(int eans, Player& player, Player::items pInventory[], Player& dealer, Player::items dInventory[], PlayerHandler& playerActions, unsigned int& damage, std::stack<int>& shotgun, bool& playerSkipped, bool& dealerSkipped);
void shootTarget(Player& player, Player::items pInventory[], Player& dealer, Player::items dInventory[], PlayerHandler& playerActions, unsigned int& damage, std::stack<int>& shotgun, bool& dealerSkipped);
void showDealerItems(Player& dealer, Player::items dealerInventory[]);
void dealerTurn(Player& player, Player::items pInventory[], Player& dealer, Player::items dInventory[], PlayerHandler& playerActions, unsigned int& damage, std::stack<int>& shotgun, bool& playerSkipped, bool& dealerSkipped);
void dealerAction(Player& player, Player::items pInventory[], Player& dealer, Player::items dInventory[], PlayerHandler& playerActions, unsigned int& damage, std::stack<int>& shotgun, bool& playerSkipped);
void dealerUseItem(int item, Player& dealer, Player::items dInventory[]);

int main() {
    srand(time(0));
    runGame();
    return 0;
};

void runGame() {
    gameState currentState = PLAYING;
    Utils utilFunction;
    std::string playerName;
    bool isInGame = true;

    while (isInGame) { //gameplay loop
        switch (currentState) {
            case gameState::MAIN_MENU:
            mainMenu(utilFunction);
            currentState = INTRO;
            break;

            case gameState::INTRO:
            intro(utilFunction, playerName);
            currentState = PLAYING;
            break;

            case gameState::PLAYING:
            playingGame();
            currentState = WIN_STATE;
            break;

            case gameState::WIN_STATE:
            break;

            case gameState::GAME_OVER:
            return;
        }
    }   
}

void mainMenu(Utils util) {
    std::string ans;
    std::cout << R"(Welcome to the C++ adaptation of Buckshot Roulette!
      Original game created by Mike Klubnika
         Programmed in C++ by Andrew Tran

Enter any key to continue:)";
    std::cin >> ans;
    util.clearScreen();
};

void intro(Utils util, std::string& name) {
    std::string ans;
    std::cout << "You find yourself in a dimly lit chamber, surrounded by metal walls on all sides, the smell of rust and the sounds of distant machinery in the distance." << std::endl;
    sleep(5);
    std::cout << "In the center lies what appears to be a game table resembling that of a casino, except that the normally inviting green felt top is instead a bleak greenish-gray metal." << std::endl;
    sleep(5);
    std::cout << "You can vaguely make out a monstrous figure in the darkness baring sharp teeth and no eyes in its sockets." << std::endl;
    sleep(2);
    std::cout << "\nEnter any key to continue: ";
    std::cin >> ans;
    util.clearScreen();

    std::cout << "It slides a form across the table." << std::endl;
    sleep(2);
    std::cout << "\n\"...PLEASE SIGN THE WAIVER.\"" << std::endl;
    sleep(2);
    std::cout << "\nGENERAL RELEASE OF LIABILITY (Rules):\n" << std::endl;
    std::cout << "The shotgun's chamber will be loaded with a random amount of rounds from three to eight." << std::endl;
    std::cout << "Some will be blank and some will be live, loaded in an unknown order. You will be told how many of each there are only one time per reload." << std::endl;
    std::cout << "It is up to you to keep track as the rounds progress." << std::endl;
    std::cout << "\nYou will take turns with the dealer, firing the shotgun. You always go first. You can either aim at yourself or the dealer." << std::endl;
    std::cout << "Shooting yourself with a blank skips the dealer's turn. Shooting the dealer with a live deals damage to him. These same rules conversely apply to the dealer on its own turn." << std::endl;
    std::cout << "\nEvery time the shotgun is reloaded, you will gain items that have beneficial effects, but beware: the dealer also obtains and uses its own items on you." << std::endl;
    std::cout << "You can view your (and the dealer's) current items and their effects whenever it is your turn." << std::endl;
    std::cout << "\nBeing shot by a single live is not necessarily the end; we have defibrillators on standby to restore you back to health. However, charges are limited." << std::endl;
    std::cout << "Once you're out of charges, it is generally considered the best course of action to not get shot by any more live rounds." << std::endl;
    std::cout << "You will be monetarily awarded depending on your performance. Assuming you live to the end." << std::endl;
    std::cout << "\nBY SIGNING YOUR NAME, YOU AGREE TO THE ABOVE TERMS: ";
    std::cin >> name;
    util.clearScreen();

    std::cout << "The dealer takes a shotgun out from beneath the table." << std::endl;
    sleep(2);
}   

void playingGame() {
    Player::items mainInventory[8] = {Player::null, Player::null, Player::null, Player::null, Player::null, Player::null, Player::null, Player::null}; //setup player's inventory 
    Player mainPlayer(4, mainInventory); //initialize both players with 4 hp and 0 items
    Player::items dealerInventory[8] = {Player::null, Player::null, Player::null, Player::null, Player::null, Player::null, Player::null, Player::null}; //setup dealer's inventory
    Player dealer(4, dealerInventory);
    Player* players[] = {&mainPlayer, &dealer};
    PlayerHandler action;
    Utils util;
    
    while(mainPlayer.getHP() > 0 && dealer.getHP() > 0) {
        unsigned int damageModifier = 1;
        bool playerSkipped = false;
        bool dealerSkipped = false;

        int totalShells = rand() % 6 + 3; //generates a random number of shells from 3 to 8;
        std::stack<int> shotgun = generateShotgun(totalShells);

        while(!shotgun.empty() && mainPlayer.getHP() > 0 && dealer.getHP() > 0) {
            std::cout << "Your charges: " << mainPlayer.getHP() << "\nDealer's charges: " << dealer.getHP() << "\n\n";
            playerTurn(mainPlayer, mainInventory, dealer, dealerInventory, action, damageModifier, shotgun, playerSkipped, dealerSkipped);

            if(!shotgun.empty()) {
            dealerTurn(mainPlayer, mainInventory, dealer, dealerInventory, action, damageModifier, shotgun, playerSkipped, dealerSkipped);
            }
        }
        
    };
    
}
    
void playerTurn(Player& player, Player::items pInventory[], Player& dealer, Player::items dInventory[], PlayerHandler& playerActions, unsigned int& damage, std::stack<int>& shotgun, bool& playerSkipped, bool& dealerSkipped) {
    Utils util;
    int ans = 0;
    
    if(playerSkipped) {
        std::cout << "Your turn was skipped." << std::endl;
        sleep(3);
        playerSkipped = false; //if the player was skipped, unskip them
    } else {
        while(ans != 1) {
        ans = chooseAction();
        executeAction(ans, player, pInventory, dealer, dInventory, playerActions, damage, shotgun, playerSkipped, dealerSkipped);
        }
    }
    damage = 1; //when the player ends their turn after using a handsaw, reset the damage modifier back to normal
    util.clearScreen();
}
  
int chooseAction() {
    Utils utilFunction;
    int selection;
    std::cout << "What do you want to do?\n1. Shoot\n2. Use items\n3. View dealer's items" << std::endl;
    std::cin >> selection;
    utilFunction.clearErrorFlag();

    while(selection < 1 || selection > 3) {
        std::cout << "Please input a valid choice." << std::endl;
        std::cin >> selection;
        utilFunction.clearErrorFlag();
    }
    return selection;
}

void executeAction(int eans, Player& player, Player::items pInventory[], Player& dealer, Player::items dInventory[], PlayerHandler& playerActions, unsigned int& damage, std::stack<int>& shotgun, bool& playerSkipped, bool& dealerSkipped) {
    Utils util;
    int target = -1;
    util.clearScreen();
    std::string dummyValue;

    switch(eans) {
        
        case 1:
        shootTarget(player, pInventory, dealer, dInventory, playerActions, damage, shotgun, dealerSkipped);
        break;

        case 2:
        
        break;

        case 3:
        showDealerItems(dealer, dInventory);
        break;
    }
}

void shootTarget(Player& player, Player::items pInventory[], Player& dealer, Player::items dInventory[], PlayerHandler& playerActions, unsigned int& damage, std::stack<int>& shotgun, bool& dealerSkipped) {
    Utils utilFunction;
    int target;
    std::string dummyValue;

    std::cout << "Who?\n1. Dealer\n2. Yourself" << std::endl;
        std::cin >> target;
        utilFunction.clearErrorFlag();

        while(target < 1 || target > 2) {
            std::cout << "Please input a valid choice." << std::endl;
            std::cin >> target;
            utilFunction.clearErrorFlag();
        }
        if(target == 1) {
            utilFunction.clearScreen();
            playerActions.shootPlayer(dealer, shotgun, damage);
        } else {
            int prevHP = player.getHP();
            utilFunction.clearScreen();
            playerActions.shootPlayer(player, shotgun, damage);
            if(player.getHP() == prevHP) { // if the player did not lose hp, A.K.A shot themselves with a blank, skip the dealer's turn.
                dealerSkipped = true;
            }
        }
        std::cout << "Enter any key to continue: ";
        std::cin >> dummyValue;
}

void showDealerItems(Player& dealer, Player::items dInventory[]) {
    Utils util;
    bool dealerHasItems = false;
    std::string dummyValue;

        for(int i = 0; i < 8; ++i) {
            if(dInventory[i] != Player::null) {
                dealerHasItems = true;
                break;
            }
        }

        std::cout << "The dealer has ";
        if(dealerHasItems) {
            dealer.printItems();
        } else {
            std::cout << "no items." << std::endl;
        }

        std::cout << "Enter any key to continue: ";
        std::cin >> dummyValue;
        util.clearScreen();
}

void dealerTurn(Player& player, Player::items pInventory[], Player& dealer, Player::items dInventory[], PlayerHandler& playerActions, unsigned int& damage, std::stack<int>& shotgun, bool& playerSkipped, bool& dealerSkipped) {
    Utils util;
    
    if(dealerSkipped) {
        std::cout << "The dealer's turn is skipped." << std::endl;
        sleep(3);
        dealerSkipped = false; //if the dealer was skipped, unskip him
    } else {
        dealerAction(player, pInventory, dealer, dInventory, playerActions, damage, shotgun, playerSkipped);
    }
    damage = 1; //if the dealer uses a handsaw, reset the damage modifier back to normal
    util.clearScreen();
}

void dealerAction(Player& player, Player::items pInventory[], Player& dealer, Player::items dInventory[], PlayerHandler& playerActions, unsigned int& damage, std::stack<int>& shotgun, bool& playerSkipped) {
    bool knowsNextBullet = false;
    bool drinksBeer = false;

    std::cout << "The dealer aims at ";
    int target = rand() % 2;

    if ((knowsNextBullet && shotgun.top() == 1) || (!knowsNextBullet && target == 1)) {
        // shoot the player if either 1) he knows the next bullet and it's live, OR 2) he doesn't know and does a random coin flip and the number is 1
        std::cout << "you." << std::endl;
        playerActions.shootPlayer(player, shotgun, damage);
    } else{
        // shoots himself if either 1) he knows the next bullet and it's blank, OR 2) he does a random coin flip and the number is 0
        std::cout << "itself." << std::endl;
        int prevHP = dealer.getHP();
        playerActions.shootPlayer(dealer, shotgun, damage);
        if(dealer.getHP() == prevHP) { // if the dealer did not lose hp, A.K.A if he shot himself with a blank, skip the player's turn.
            playerSkipped = true;
        }
    } 
}

void dealerUseItem(int item, Player& dealer, Player::items dInventory[]) {
    //make the dealer use an item
}