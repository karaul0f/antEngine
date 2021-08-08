#pragma once
#include "Sound.h"

namespace Resources
{
//-----------------------------------------------------------------
Sound::Sound(std::string filePath, sf::SoundBuffer& buffer)
{
	m_filePath = filePath;
	m_sound.setBuffer(buffer);
}
//-----------------------------------------------------------------
sf::Sound& Sound::GetSound()
{
	return m_sound;
}
//-----------------------------------------------------------------
std::string& Sound::GetFilePath()
{
	return m_filePath;
}
//-----------------------------------------------------------------
}

