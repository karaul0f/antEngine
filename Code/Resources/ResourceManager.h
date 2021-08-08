#pragma once
#include <string>
#include <unordered_map>
#include "LevelLoader.h"
#include "SFML/Graphics.hpp"
#include "Resources/Types/Music.h"
#include "Resources/Types/Sound.h"
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

		std::unordered_map<std::string, sf::Texture>		m_textures;
		std::unordered_map<std::string, Music>				m_musics;

		std::unordered_map<std::string, Sound>				m_sounds;
		std::unordered_map<std::string, sf::SoundBuffer>	m_soundBuffers;

		// ��������� ������� ��� ����
		void ResourceLoad();

		// ������ ���� � ����� 
		std::string CreatePath(const std::string& path);
		
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

		// �������� �������� �� �����
		sf::Texture& GetTexureByName(const std::string& name);

		// �������� ������ �� �����
		Music& GetMusicByName(const std::string& name);

		// �������� ���� �� �����
		Sound& GetSoundByName(const std::string& name);
	};
}
