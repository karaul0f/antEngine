#pragma once

namespace tgui {
	class GuiSFML;
}

namespace GUI
{
	// ��������� ���� GUI � ����
	class IWindow
	{
	public:
		// ���������� ��������� ����
		virtual void Activate(tgui::GuiSFML* gui) = 0;

		// ���������� ����������� ����
		virtual void Deactivate() = 0;
	};
}
