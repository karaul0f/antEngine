#pragma once
#include "IState.h"

namespace Gameplay
{
	// Cостояние меню
	class MenuState : public IState
	{
	public:
		void Activate() override;
		void Deactivate() override;
		void OnFrame() override;
	};
}
