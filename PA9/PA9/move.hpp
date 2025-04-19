#pragma once

#include "include.hpp"

class Move {
public:


private:
    std::string moveName;
    double power,	 // Multiplier
           speed,
           accuracy;
    int maxMoveCount, // # of times a move can be used
        currentMoveCount;
    char moveType; 

    // some sort of status eefect moodifier
    // an array to hold status effect things;
};