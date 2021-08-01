#pragma once
#include <memory>
#include "TGUI/TGUI.hpp"
#include "GUI/Windows/IWindow.h"

namespace sf {
	class RenderWindow;
}

namespace GUI
{
	// ����� ��� ��������� GUI ����
	class GUI
	{
		std::unique_ptr<IWindow> m_currentWindow;
		
		tgui::GuiSFML m_gui;
	public:
		// ���������� ������� ������� �����
		void HandleEvent(sf::Event sfmlEvent);
		
		// ��������� ������������� GUI ����
		void Init();

		// ��������� GUI ���� �� ������ �����
		void OnFrame();

		// ���������� ���� GUI ��� ���������
		void SetWindow(IWindow* window);
	};
}
