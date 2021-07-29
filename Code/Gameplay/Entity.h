#pragma once
#include "SFML/Graphics.hpp"

namespace Render
{
	class Entity;
}

namespace Gameplay
{
	// ������� ��������
	class Entity
	{
		bool m_isActive;

	public:
		Entity();

		// ������� �� ��� ������� ��������
		bool IsActive();

		// ��������� ����� ������� ��������
		void OnFrame();
	};
}