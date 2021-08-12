#pragma once
#include "IComponent.h"

namespace Gameplay
{
	// ��������� ��� ����������� ������� ��������
	class GraphicComponent: public IComponent
	{
	public:
		// ��������� ����������
		void Activate() override;

		// ����������� ����������
		void Deactivate() override;

		// ��������� ����� ������� ������
		void OnFrame() override;
	};
}