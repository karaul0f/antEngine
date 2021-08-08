#pragma once
#include "SFML/Audio.hpp"

namespace Resources
{
	// Сущность для хранения музыки и пути к ней
	class Music
	{
		sf::Music	m_music;
		std::string m_filePath;
	public:
		Music() {};
		Music(std::string filePath);

		// Получить музыку
		sf::Music& GetMusic();

		// Получить путь до музыки
		std::string& GetFilePath();
	};
}