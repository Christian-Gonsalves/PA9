#include "character.hpp"

class EnemyCharacter : public Character {
public:

	void setCatchPhrase(const string newPhrase);

	string getCatchPhrase(void) const;


private:
	string catchPhrase;

};