#pragma once

#include "include.hpp"

class Moves {
public:


private:
    std::string moveName;
    double power,	 // Multiplier
           speed,
           accuracy;
    int moveCount; // Max # of times a move can be used
    char moveType; 

    // some sort of status eefect moodifier
    // an array to hold status effect things;
};