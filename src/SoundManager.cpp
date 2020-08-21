#include "SoundManager.h"

SoundManager::SoundManager() {
	Mix_OpenAudio(22050, AUDIO_S16, 2, 4096);
}

SoundManager::~SoundManager() {

	for ( auto it = sound_fxs.begin(); it != sound_fxs.end(); ++it ) {
		Mix_FreeChunk( (*it).second );
	}

	for ( auto it = music.begin(); it != music.end(); ++it ) {
		Mix_FreeMusic( (*it).second );
	}

}


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
