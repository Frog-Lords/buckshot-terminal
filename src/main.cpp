#include "../include/generate_shotgun.h"
#include "../include/Player.h"
#include "../include/PlayerHandler.h"
#include <string>
#include "../include/Utils.h"


int main() {
    Player::items mainInventory [] = {Player::beer, Player::cuffs, Player::cigPack, Player::cuffs, Player::mGlass, Player::saw}; 
    Player mainPlayer(4, mainInventory);
    Player enemy;
    PlayerHandler playerManager;
    Utils utilityManager;

    static const int TOTAL_PLAYERS = 2;
    Player* players[] = {&mainPlayer, &enemy};

// DECLARATION ZONE ^^^^
    std::cout << R"(
Welcome to Buckshot Roulette Terminal Edition!

The air is thick with the smell of rust and old wood.
You find yourself in a dimly lit room. 
The only light coming from a flickering bulb that swings gently overhead.
Eerie shadows linger on the walls.
The walls themselves are lined with peeling paint and old, yellowed newspaper clippings.
A heavy silence hangs in the air, only broken by the distant dripping of water.

Enter Any Key to Continue!

)";

    std::string dummyValue;
    std::cin >> dummyValue;
    utilityManager.clearScreen();

    std::cout << R"(
As your eyes adjust to the dim light, you notice a figure in the corner.
It's hard to tell their age, gender, or even if they're human, their features shrouded in shadows and a thick, tattered cloak.
The figure's hands are steady, holding a faded document outstretched towards you.
As you step closer, a cold draft chills your spine.

The document reads:

'Take A Game of Chance For It is All You Got Left
These are the following rules if you wish to partake
Oh dear Oh my What Choice Do You Have to Make
It is clear to see you don't have what it takes'

The figure doesn't move, but their unseen eyes seem to pierce through you, waiting for your decision. What will you do?

)";

    //playerManager.printHealth(players, TOTAL_PLAYERS);
    //mainPlayer.printItems();
    //std::stack <int> shotgun = generate_shotgun(5);
    //std::cout<< shotgun.top()<<std::endl;
    
};
