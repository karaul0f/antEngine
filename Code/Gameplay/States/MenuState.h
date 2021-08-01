#pragma once
#include "IState.h"

namespace Gameplay
{
	// C�������� ����
	class MenuState : public IState
	{
	public:
		void Activate() override;
		void Deactivate() override;
		void OnFrame() override;
	};
}
