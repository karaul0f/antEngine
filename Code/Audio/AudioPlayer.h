#pragma once
#include <unordered_map>
#include "SFML/Audio.hpp"
#include "Resources/Types/Music.h"
#include "Resources/Types/Sound.h"
#include "Core/Ini.h"

namespace 
{
	typedef std::unordered_map<std::string, sf::Music*> MapMusic;
	typedef std::unordered_map<std::string, sf::Sound*> MapSound;
}

namespace Audio
{
	// ������������� ������ � ������
	class AudioPlayer
	{
		AudioPlayer() { }
		AudioPlayer(const AudioPlayer& instance) = delete;
		AudioPlayer& operator=(const AudioPlayer&) = delete;
		
		~AudioPlayer();

		MapMusic m_musics;
		MapSound m_sounds;

		Core::Ini	m_soundSettings;
		float		m_volumeLevel;

	public:
		static AudioPlayer& Instance()
		{
			static AudioPlayer instance;
			return instance;
		}
		
		// ���������������� ����������
		void Init();
		
		// ��������� ����
		void PlaySound(Resources::Sound& sound);

		// ��������� ������
		void PlayMusic(Resources::Music& music, bool repeat);

		// ���������� ��� �����
		void StopAllSounds();

		// ���������� ��������� ������ � ������
		void SetVolume(float volume);

		// �������� ������� ��������� ������ � ������
		float GetVolume();

	};
}
