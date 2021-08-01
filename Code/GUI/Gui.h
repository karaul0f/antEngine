#pragma once
#include <memory>
#include "TGUI/TGUI.hpp"

namespace sf {
	class RenderWindow;
}

namespace GUI
{
	// ����� ��� ��������� GUI ����
	class GUI
	{
		bool m_isFirstFrame;
		
		tgui::GuiSFML m_gui;
	public:
		// ���������� ������� ������� �����
		void HandleEvent(sf::Event sfmlEvent);
		
		// ��������� ������������� GUI ����
		void Init();

		// ��������� GUI ���� �� ������ �����
		void OnFrame();
	};
}
