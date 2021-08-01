#pragma once
#include "Entity.h"
#include <memory>
#include <vector>

namespace Gameplay
{
	// ������� ������� GameState'�
	class Level
	{
		std::vector<Entity> m_entities;
	public:
		// �������� ��� ��������� ������
		void Activate();

		// �������� ��� ����������� ������
		void Deactivate();
		
		// ��������� ������ �� ������ �����
		void OnFrame();
	};

}
