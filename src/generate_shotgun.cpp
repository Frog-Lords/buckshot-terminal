// generate_shotgun.cpp

#include "../include/generate_shotgun.h"
#include <stack>
#include <algorithm> // For std::shuffle
#include <random>    // For std::default_random_engine
#include <iostream>

std::stack<int> generate_shotgun(unsigned int bulletCount) {
    std::stack<int> shotgun;
    std::random_device random;  // Non-deterministic random number generator
    std::mt19937 gen(random()); // Standard mersenne_twister_engine seeded with random()

    int values[bulletCount];
    int maxZeros = bulletCount / 2 + 1; // Allow one more or one less zero
    int zerosCount = 0;

    // Populate the array with a balanced approach
    for (int i = 0; i < bulletCount; i++) {
        if (zerosCount < maxZeros && gen() % 2 == 0) { // Flip a coin to decide, but check if maxZeros limit is reached
            values[i] = 0;
            zerosCount++;
        } else {
            values[i] = 1;
        }
    }

    // Shuffle the array to randomize the order further
    std::shuffle(values, values + bulletCount, gen);

    // Push the values onto the stack
    for (int value : values) {
        shotgun.push(value);
    }

    return shotgun;
}
