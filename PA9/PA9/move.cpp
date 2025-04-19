#include "move.hpp"

Move::Move(string newName, string newPhrase, double newPower, double newSpeed, double newAccuracy, int newMoveCnt, char newType, int* newStatus)
{
	moveName = newName;
	movePhrase = newPhrase;
	power = newPower;
	speed = newSpeed;
	accuracy = newAccuracy;
	moveCount = newMoveCnt;
	moveType = newType;
	*statusEffect = *newStatus;
}

Move::~Move()
{
}

void Move::setMoveName(const string newName)
{
	moveName = newName;
}

void Move::setMovePhrase(const std::string newPhrase) {
	movePhrase = newPhrase;
}

void Move::setPower(double newPower) {
	power = newPower;
}

void Move::setSpeed(double newSpeed) {
	speed = newSpeed;
}

void Move::setAccuracy(double newAccuracy) {
	accuracy = newAccuracy;
}

void Move::setMoveCount(int newCount) {
	moveCount = newCount;
}

void Move::setMoveType(char newType) {
	moveType = newType;
}

void Move::setEffectArray(int index, int turns, int strength)
{
	statusEffect[index] = turns;
	statusEffect[index + 1] = strength;
}

string Move::getMoveName() const {
	return moveName;
}

string Move::getMovePhrase() const {
	return movePhrase;
}

double Move::getPower() const {
	return power;
}

double Move::getSpeed() const {
	return speed;
}

double Move::getAccuracy() const {
	return accuracy;
}

int Move::getMoveCount() const {
	return moveCount;
}

char Move::getMoveType() const {
	return moveType;
}

int Move::getEffectTurns(int index)
{
	return this->statusEffect[index];
}

int Move::getEffectStrength(int index)
{
	return this->statusEffect[index+1];
}
