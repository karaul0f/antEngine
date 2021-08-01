#pragma once
#include "SFML/Audio.hpp"

namespace Audio
{
	// Проигрыватель музыки и звуков
	class AudioPlayer
	{
		AudioPlayer() { }
		AudioPlayer(const AudioPlayer& instance) = delete;
		AudioPlayer& operator=(const AudioPlayer&) = delete;
	public:
		static AudioPlayer& Instance()
		{
			static AudioPlayer instance;
			return instance;
		}
		
		// Инициализировать аудиоплеер
		void Init();
		
		// Проиграть звук
		void PlaySound(sf::Sound& sound);

		// Проиграть музыку
		void PlayMusic(sf::Music& music, bool repeat);

		// Остановить все звуки
		void StopAllSounds();

		// Установить громкость музыки
		void SetMusicVolume(float volume);

		// Установить громкость звуков
		void SetSoundVolume(float volume);
	};
}
