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
	// Управление ресурсами игры (загрузка, изменение, экспорт...)
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
		
		// Запускаем загрузку ресурсов игры
		void Init();

		// Уничтожаем все ресурсы
		void Deinit();

		// Загружаем ресурсы для игры
		void ResourceLoad();

		// Создаём путь к файлу 
		std::string CreatePath(std::string path);

		// Получаем спрайт по имени
		sf::Sprite& GetSpriteByName(std::string name);

		// Получаем музыку по имени
		sf::Music& GetMusicByName(std::string name);

		// Получаем звук по имени
		sf::Sound& GetSoundByName(std::string name);
	};
}
