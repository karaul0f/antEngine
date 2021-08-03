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
		std::map<std::string, sf::Music>		m_musics;
		std::map<std::string, sf::SoundBuffer>	m_soundBuffers;
		
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
		const std::string& CreatePath(const std::string& path);

		// Получаем спрайт по имени
		sf::Texture& GetTexureByName(const std::string& name);

		// Получаем музыку по имени
		sf::Music& GetMusicByName(const std::string& name);

		// Получаем звук по имени
		sf::SoundBuffer& GetSoundBufferByName(const std::string& name);
	};
}
