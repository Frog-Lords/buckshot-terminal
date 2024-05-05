#include <iostream>
#include <limits>
#include "../include/Utils.h"

bool Utils::os_determiner(){
    #ifdef _WIN32
    bool os = true;
    #elif __unix__ || __unix || unix || __APPLE__ || __MACH__ || __linux__
    bool os = false;
    #else
    std::cout << "Unknown OS\n";
    exit;
    #endif
    return os;
}

void Utils::clearScreen(){ //clears the terminal screen for optimal gaming experience
    bool isWindows = os_determiner();
    if(isWindows == true){
        system("cls");
        return;
    }
    system("clear");
}

void Utils::clearErrorFlag() { //run directly after a non-string cin to avoid everything breaking
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}