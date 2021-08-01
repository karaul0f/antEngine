#include "Gameplay.h"
#include "../Core/Logger.h"
#include "States/GameState.h"

namespace Gameplay
{
//-----------------------------------------------------------------
void Gameplay::Init()
{
	INFO("Инициализация игровой логики");
	
	m_isRun = true;
	m_currentState = std::make_unique<GameState>();
	m_currentState->Activate();
}
//-----------------------------------------------------------------
void Gameplay::OnFrame()
{
	m_currentState->OnFrame();
}
//-----------------------------------------------------------------
bool Gameplay::IsRun()
{
	return m_isRun;
}
//-----------------------------------------------------------------
}
