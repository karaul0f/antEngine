#include "Gameplay.h"
#include "../Core/Logger.h"
#include "GUI/Gui.h"
#include "States/MenuState.h"

namespace Gameplay
{
//-----------------------------------------------------------------
void Gameplay::Init()
{
	INFO("Инициализация игровой логики");
	
	m_isRun = true;

	SetState(std::move(new MenuState));
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
void Gameplay::Close()
{
	m_isRun = false;
}
//-----------------------------------------------------------------
void Gameplay::SetState(IState* state)
{
	if (m_currentState != nullptr)
		m_currentState->Deactivate();
	
	m_currentState = std::unique_ptr<IState>(state);
	m_currentState->Activate();
}
//-----------------------------------------------------------------
}
