#pragma once
#include "Music.h"

namespace Resources
{

	Music::Music(std::string filePath)
	{
		m_filePath = filePath;
		m_music.openFromFile(filePath);
	}

	sf::Music& Music::GetMusic()
	{
		return m_music;
	}

	std::string& Music::GetFilePath()
	{
		return m_filePath;
	}

}

