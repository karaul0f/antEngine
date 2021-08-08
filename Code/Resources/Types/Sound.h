#pragma once
#include "SFML/Audio.hpp"

namespace Resources
{
	// Сущность для хранения звука и пути к нему
	class Sound
	{
		sf::Sound	m_sound;
		std::string m_filePath;
	public:
		Sound() {};
		Sound(std::string filePath, sf::SoundBuffer& buffer);

		// Получить звук
		sf::Sound& GetSound();

		// Получить путь до звука
		std::string& GetFilePath();
	};
}