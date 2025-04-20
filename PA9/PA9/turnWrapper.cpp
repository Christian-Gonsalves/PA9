#pragma once

#include "turnWrapper.hpp"

bool TurnWrapper::runBattle() {
	while (isBattleOver() == false) {


	}
}

bool TurnWrapper::isBattleOver() {
	if (enemy->getCurrentHealth() > 0 && player->getCurrentHealth()) {
		return true;
	}
	return false;
}