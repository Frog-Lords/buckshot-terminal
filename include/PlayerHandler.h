#pragma once
#include <iostream>
#include <iomanip>
#include <stack>
#include "../include/Player.h"
#include <unistd.h>

struct PlayerHandler
{
void printHealth(Player* targets[], int size);
int promptItem(Player& target);
void shootPlayer(Player& target, std::stack<int>& shotgun, unsigned int modifier=1); //shoot other Player by reference of their object
int useItem(Player& target, int indexChoice, std::stack<int> shotgun); //inventory [index] gives corresponding item provides prompt are you sure yes/no

};


