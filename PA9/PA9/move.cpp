#include "move.hpp"

Move::Move(string newName, string newPhrase, double newPower, double newSpeed, double newAccuracy, int newMaxMoveCnt, char newType, int* newStatus)
{
	moveName = newName;
	movePhrase = newPhrase;
	power = newPower;
	speed = newSpeed;
	accuracy = newAccuracy;
	maxMoveCount = newMaxMoveCnt;
	currentMoveCount = newMaxMoveCnt;
	moveType = newType;
	if (newStatus == nullptr) {
		for (int i = 0; i < 10; ++i) {
			statusEffect[i] = 0;
		}
	}
	else {
		for (int i = 0; i < 10; ++i) {
			statusEffect[i] = newStatus[i];
		}
	}

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

void Move::setMaxMoveCount(int newMaxCount) {
	maxMoveCount = newMaxCount;
}

void Move::setCurMoveCount(int newCurCount)
{
	currentMoveCount = newCurCount;
}

void Move::setMoveType(char newType) {
	moveType = newType;
}

void Move::setEffectArray(const int *newArray)
{
	for (int i = 0; i < 10; i++) {
		statusEffect[i] = newArray[i];
	}
}

void Move::setEffectAttribute(int index, int turns, int strength)
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

int Move::getMaxMoveCount() const {
	return maxMoveCount;
}

int Move::getCurMoveCount(void) const
{
	return currentMoveCount;
}

char Move::getMoveType() const {
	return moveType;
}

const int* Move::getEffectArray(void) const
{
	return statusEffect;
}

int Move::getEffectTurns(int index)
{
	return this->statusEffect[index];
}

int Move::getEffectStrength(int index)
{
	return this->statusEffect[index+1];
}

Move& Move::operator=(const Move& rhs)
{

	this->setMoveName(rhs.getMoveName());
	this->setMovePhrase(rhs.getMovePhrase());
	this->setPower(rhs.getPower());
	this->setSpeed(rhs.getSpeed());
	this->setAccuracy(rhs.getAccuracy());
	this->setMaxMoveCount(rhs.getMaxMoveCount());
	this->setCurMoveCount(rhs.getCurMoveCount());
	this->setMoveType(rhs.getMoveType());
	this->setEffectArray(rhs.getEffectArray());

	return *this;
}
