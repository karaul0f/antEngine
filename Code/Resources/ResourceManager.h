#pragma once
#include <string>
#include <unordered_map>

#include "LevelLoader.h"
#include <map>
#include "SFML/Graphics.hpp"
#include <SFML/Audio/Music.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

namespace Resources
{
	// ���������� ��������� ���� (��������, ���������, �������...)
	class ResourceManager
	{
	private:
		ResourceManager() {}
		ResourceManager(const ResourceManager& instance) = delete;
		ResourceManager& operator=(const ResourceManager&) = delete;

		std::map<std::string, sf::Texture>		m_textures;
		std::map<std::string, sf::Sprite>		m_sprites;
		std::map<std::string, sf::Music>		m_musics;
		
		std::map<std::string, sf::SoundBuffer>	m_soundBuffers;
		std::map<std::string, sf::Sound>		m_sounds;
	public:
		static ResourceManager& Instance()
		{
			static ResourceManager instance;
			return instance;
		}
		
		// ��������� �������� �������� ����
		void Init();

		// ���������� ��� �������
		void Deinit();

		// ��������� ������� ��� ����
		void ResourceLoad();

		// ������ ���� � ����� 
		std::string CreatePath(std::string path);

		// �������� ������ �� �����
		sf::Sprite& GetSpriteByName(std::string name);

		// �������� ������ �� �����
		sf::Music& GetMusicByName(std::string name);

		// �������� ���� �� �����
		sf::Sound& GetSoundByName(std::string name);
	};
}
