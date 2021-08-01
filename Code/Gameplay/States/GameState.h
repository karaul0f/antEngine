#pragma once
#include "IState.h"
#include "Gameplay/Entity.h"
#include "Gameplay/Level.h"

namespace Gameplay
{
	// Cостояние геймплея
	class GameState: public IState
	{
		std::unique_ptr<Level> m_currentLevel;
	
	public:
		void Activate() override;
		void Deactivate() override;
		void OnFrame() override;
	};

}
