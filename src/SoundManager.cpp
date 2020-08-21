#include "SoundManager.h"
#include <iostream>

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

	Mix_CloseAudio();
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


bool SoundManager::load(const std::string & file_name, const std::string & id,
								const sound_type & type) {
	bool success = true;

	if ( type == sound_type::SOUND_MUSIC ) {
		Mix_Music * new_music = Mix_LoadMUS( file_name.c_str() );

		if ( new_music == nullptr ) {
			std::cerr << "ERROR: Could not load the music " << file_name
						 << std::endl << Mix_GetError() << std::endl;

			success = false;
		} else {
			music[id] = new_music;
			success = true;
		}

	} else if ( type == sound_type::SOUND_SFX ) {
		Mix_Chunk * new_fx = Mix_LoadWAV( file_name.c_str() );

		if ( new_fx == nullptr ) {
			std::cerr << "ERROR: Could not load SFX " << file_name
						 << std::endl << Mix_GetError() << std::endl;

			success = false;
		} else {
			sound_fxs[id] = new_fx;
			success = true;
		}

	}

	return success;

}


void SoundManager::playMusic(const std::string & id, const int loop){
	auto it = music.find(id);

	if ( it == music.end() ) {
		std::cerr << "ERROR: No music with the id: " << id << std::endl;
	} else {
		Mix_PlayMusic(music[id], loop);
	}
}


void SoundManager::playSound(const std::string & id, const int loop){
	auto it = sound_fxs.find(id);

	if ( it == sound_fxs.end() ) {
		std::cerr << "ERROR: No SFC with the id: " << id << std::endl;
	} else {
		Mix_PlayChannel(-1, sound_fxs[id], loop);
	}
}
