#include "character.hpp"

class EnemyCharacter : public Character {
public:

	void setCatchPhrase(const string newPhrase);

	string getCatchPhrase(void) const;

	void readFromFile(EnemyCharacter& n, ifstream& instream);

private:
	string catchPhrase;

};