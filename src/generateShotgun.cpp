#include "../include/generateShotgun.h"
#include <iostream>
std::stack<int> generateShotgun(int bulletCount) {
    enum chamberState { BLANK, LIVE };

    int blankShells, liveShells;
    int chamber[8] = { BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK, BLANK}; //empty chamber to start

    if(bulletCount == 2 || bulletCount == 3) {
        liveShells = 1;
    } else if(bulletCount == 4) {
        liveShells = 2;
    } else if(bulletCount == 5) {
        liveShells = rand() % 2 + 2; // 2 or 3
    } else if(bulletCount == 6) {
        liveShells = 3;
    } else if(bulletCount == 7) {
        liveShells = rand() % 2 + 3; //3 or 4
    } else {
        liveShells = 4;
    }

    for(int i = 0; i < liveShells; i++) {
        int rnd;
        do {
            rnd = rand() % bulletCount; //chooses a random bullet index
        } while (chamber[rnd] == LIVE); //ensures each live is placed in a different spot
        chamber[rnd] = LIVE; //load the live into the chamber if it's free
    }

    blankShells = bulletCount - liveShells;

    std::cout << "\"" << liveShells << " LIVE. " << blankShells << " BLANK.\"\n";

    std::stack<int> shotgun;
    for(int i = 0; i < bulletCount; i++) {
        shotgun.push(chamber[i]);
    }
    
    return shotgun;
}