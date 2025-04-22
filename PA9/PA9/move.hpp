#pragma once

#include "include.hpp"

class Move {
public:
    Move(string newName = "", string newPhrase = "", double newPower = 0, double newSpeed = 0, double newAccuracy = 0,
        int newMaxMoveCnt = 0, int newCurMoveCnt = 0, char newType = '\n', int* newStatus = nullptr);

    ~Move();

    void setMoveName(const string newName);
    void setMovePhrase(const string newPhrase);
    void setPower(double newPower);
    void setSpeed(double newSpeed);
    void setAccuracy(double newAccuracy);
    void setMaxMoveCount(int newMaxCount);
    void setCurMoveCount(int newCurCount);
    void setMoveType(char newType);
    void setEffectArray(const int* newArray);
    void setEffectAttribute(int index, int turns, int strength);

    string getMoveName(void) const;
    string getMovePhrase(void) const;
    double getPower(void) const;
    double getSpeed(void) const;
    double getAccuracy(void) const;
    int getMaxMoveCount(void) const;
    int getCurMoveCount(void) const;
    char getMoveType(void) const;
    const int* getEffectArray(void) const;
    int getEffectTurns(int index);
    int getEffectStrength(int index);

    Move& operator= (const Move& rhs);

private:
    string moveName;
    string movePhrase;
    double power,	 // Multiplier
           speed,
           accuracy;
    int maxMoveCount, // # of times a move can be used
        currentMoveCount;
    char moveType; 
    int statusEffect[10];
    
    // some sort of status eefect moodifier
    // an array to hold status effect things;
};

