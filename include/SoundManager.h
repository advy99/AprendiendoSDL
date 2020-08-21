#ifndef SOUNDMANAGER_H_INCLUDED
#define SOUNDMANAGER_H_INCLUDED

#include <string>
#include <map>
#include <SDL2/SDL_mixer.h>

enum sound_type {
	SOUND_MUSIC = 0,
	SOUND_SFX   = 1
};


class SoundManager {
	private:

		static SoundManager * instance;
		SoundManager();
		~SoundManager();

		std::map<std::string, Mix_Chunk *> sound_fxs;
		std::map<std::string, Mix_Music *> music;

	public:
		SoundManager(const SoundManager &) = delete;
		SoundManager & operator=(const SoundManager &) = delete;

		static SoundManager * getInstance();

		bool load(const std::string & file_name, const std::string & id,
					 const sound_type & type);

		void playSound(const std::string & id, const int loop);
		void playMusic(const std::string & id, const int loop);

		void clean();

};

#endif
