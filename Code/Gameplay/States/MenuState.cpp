#include "MenuState.h"

#include "GUI/Windows/MainMenuWindow.h"
#include "Render/Render.h"

namespace Gameplay
{
//-----------------------------------------------------------------
void MenuState::OnFrame()
{
	
}
//-----------------------------------------------------------------
void MenuState::Activate()
{
	Render::Render::Instance().GetGUI()->SetWindow(new GUI::MainMenuWindow);
}
//-----------------------------------------------------------------
void MenuState::Deactivate()
{

}
//-----------------------------------------------------------------
}
