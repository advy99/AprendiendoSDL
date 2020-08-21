#include "SoundManager.h"


SoundManager * SoundManager::getInstance() {
	if ( instance == nullptr ) {
		instance = new SoundManager();
	}

	return instance;
}

void SoundManager::clean() {
	if ( instance != nullptr )
		delete instance;
}
