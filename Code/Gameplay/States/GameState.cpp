#include "GameState.h"

namespace Gameplay
{
//-----------------------------------------------------------------
void GameState::OnFrame()
{
	m_currentLevel->OnFrame();
}
//-----------------------------------------------------------------
void GameState::Activate()
{
	m_currentLevel = std::make_unique<Level>();
	m_currentLevel->Activate();
}
//-----------------------------------------------------------------
void GameState::Deactivate()
{
	
}
//-----------------------------------------------------------------
}