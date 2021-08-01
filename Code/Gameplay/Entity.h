#pragma once
#include "SFML/Graphics.hpp"
#include "Components/IComponent.h"

namespace Gameplay
{
	// ������� ��������
	class Entity
	{
		bool m_isActive;
		
		std::vector<std::shared_ptr<IComponent>> m_components;
	public:
		Entity();

		// ������� �� ��� ������� ��������
		bool IsActive();

		// ��������� ����� ������� ��������
		virtual void OnFrame();
	};
}