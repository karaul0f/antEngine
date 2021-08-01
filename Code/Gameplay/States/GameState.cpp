#include "GameState.h"

#include "GUI/Windows/InGameWindow.h"
#include "Render/Render.h"

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
	Render::Render::Instance().GetGUI()->SetWindow(new GUI::InGameWindow);
}
//-----------------------------------------------------------------
void GameState::Deactivate()
{
	
}
//-----------------------------------------------------------------
}
