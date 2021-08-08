#pragma once
#include "SFML/Audio.hpp"

namespace Resources
{
	// �������� ��� �������� ����� � ���� � ����
	class Sound
	{
		sf::Sound	m_sound;
		std::string m_filePath;
	public:
		Sound() {};
		Sound(std::string filePath, sf::SoundBuffer& buffer);

		// �������� ����
		sf::Sound& GetSound();

		// �������� ���� �� �����
		std::string& GetFilePath();
	};
}