#include "character.hpp"

class EnemyCharacter : public Character {
public:

	void setCatchPhrase(const string newPhrase);

	string getCatchPhrase(void) const;

	void readFromFile(EnemyCharacter& n, string fileName);

private:
	string catchPhrase;

};