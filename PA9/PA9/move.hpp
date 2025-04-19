#pragma once

#include "include.hpp"

class Move {
public:
    Move(string newName = "", string newPhrase = "", double newPower = 0, double newSpeed = 0, double newAccuracy = 0,
        int newMoveCnt = 0, char newType = '\n', int newIndex = 0, int newDur = 0, int newStrength = 0);

    ~Move();

    void setMoveName(const string newName);
    void setMovePhrase(const string newPhrase);
    void setPower(double newPower);
    void setSpeed(double newSpeed);
    void setAccuracy(double newAccuracy);
    void setMoveCount(int newCount);
    void setMoveType(char newType);
    void setEffectIndex(int newIndex);
    void setEffectDuration(int newDuration);
    void setEffectStrength(int newStrength);

    string getMoveName() const;
    string getMovePhrase() const;
    double getPower() const;
    double getSpeed() const;
    double getAccuracy() const;
    int getMoveCount() const;
    char getMoveType() const;
    int getEffectIndex() const;
    int getEffectDuration() const;
    int getEffectStrength() const;

private:
    string moveName;
    string movePhrase;
    double power,	 // Multiplier
           speed,
           accuracy;
    int moveCount; // Max # of times a move can be used 
    char moveType; 
    int effectIndex;
    int effectDuration;
    int effectStrength;

    // some sort of status eefect moodifier
    // an array to hold status effect things;
};