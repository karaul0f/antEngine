#include "Core/Logger.h"
#include "Gameplay/Gameplay.h"
#include "Input/Input.h"
#include "Resources/ResourceManager.h"
#include "Render/Render.h"

int main()
{
	INFO("antEngine был запущен");
	
	// Инициализация основных подсистем движка
	Resources::ResourceManager::Instance().Init();
	Gameplay::Gameplay::Instance().Init();
	Render::Render::Instance().Init();
	Input::Input::Instance().Init();
	//Gui.Init();
	//ScriptManager.Init();

	while(Gameplay::Gameplay::Instance().IsRun())
	{
		Input::Input::Instance().OnFrame();
		Gameplay::Gameplay::Instance().OnFrame();
		Render::Render::Instance().OnFrame();
	}

	INFO("antEngine прекратил свою работу");
}