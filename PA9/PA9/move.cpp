#include "move.hpp"

<<<<<<< HEAD
Move::Move(string newName, string newPhrase, double newPower, double newSpeed, double newAccuracy, int newMoveCnt, char newType, int* newStatus)
=======
Move::Move(string newName, string newPhrase, double newPower, double newSpeed, double newAccuracy, int newMaxMoveCnt, char newType, int* newStatus)
>>>>>>> andres-2
{
	moveName = newName;
	movePhrase = newPhrase;
	power = newPower;
	speed = newSpeed;
	accuracy = newAccuracy;
<<<<<<< HEAD
	moveCount = newMoveCnt;
	moveType = newType;
	if (newStatus == nullptr) {
=======
	maxMoveCount = newMaxMoveCnt;
	currentMoveCount = newMaxMoveCnt;
	moveType = newType;
	if (newStatus == nullptr) {
		for (int i = 0; i < 10; ++i) {
			statusEffect[i] = 0;
		}
>>>>>>> andres-2
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

<<<<<<< HEAD
void Move::setMoveCount(int newCount) {
	moveCount = newCount;
=======
void Move::setMaxMoveCount(int newMaxCount) {
	maxMoveCount = newMaxCount;
}

void Move::setCurMoveCount(int newCurCount)
{
	currentMoveCount = newCurCount;
>>>>>>> andres-2
}

void Move::setMoveType(char newType) {
	moveType = newType;
}

<<<<<<< HEAD
void Move::setEffectArray(const int* newArray)
=======
void Move::setEffectArray(const int *newArray)
>>>>>>> andres-2
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

<<<<<<< HEAD
int Move::getMoveCount() const {
	return moveCount;
=======
int Move::getMaxMoveCount() const {
	return maxMoveCount;
}

int Move::getCurMoveCount(void) const
{
	return currentMoveCount;
>>>>>>> andres-2
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
<<<<<<< HEAD
	return this->statusEffect[index + 1];
=======
	return this->statusEffect[index+1];
>>>>>>> andres-2
}

Move& Move::operator=(const Move& rhs)
{

	this->setMoveName(rhs.getMoveName());
	this->setMovePhrase(rhs.getMovePhrase());
	this->setPower(rhs.getPower());
	this->setSpeed(rhs.getSpeed());
	this->setAccuracy(rhs.getAccuracy());
<<<<<<< HEAD
	this->setMoveCount(rhs.getMoveCount());
=======
	this->setMaxMoveCount(rhs.getMaxMoveCount());
	this->setCurMoveCount(rhs.getCurMoveCount());
>>>>>>> andres-2
	this->setMoveType(rhs.getMoveType());
	this->setEffectArray(rhs.getEffectArray());

	return *this;
<<<<<<< HEAD
}
=======
}
>>>>>>> andres-2
