#pragma once
#include "SFML/Audio.hpp"

namespace Audio
{
	// ������������� ������ � ������
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
		
		// ���������������� ����������
		void Init();
		
		// ��������� ����
		void PlaySound(sf::Sound& sound);

		// ��������� ������
		void PlayMusic(sf::Music& music, bool repeat);

		// ���������� ��� �����
		void StopAllSounds();

		// ���������� ��������� ������
		void SetMusicVolume(float volume);

		// ���������� ��������� ������
		void SetSoundVolume(float volume);
	};
}
