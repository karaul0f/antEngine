#pragma once
#include "SFML/Audio.hpp"

namespace Resources
{
	// Графическая сущность для отрисовки
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