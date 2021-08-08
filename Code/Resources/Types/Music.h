#pragma once
#include "SFML/Audio.hpp"

namespace Resources
{
	// �������� ��� �������� ������ � ���� � ���
	class Music
	{
		sf::Music	m_music;
		std::string m_filePath;
	public:
		Music() {};
		Music(std::string filePath);

		// �������� ������
		sf::Music& GetMusic();

		// �������� ���� �� ������
		std::string& GetFilePath();
	};
}