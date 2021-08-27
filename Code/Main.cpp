#include "Audio/AudioPlayer.h"
#include "Core/Logger.h"
#include "Core/Ini.h"
#include "Gameplay/Gameplay.h"
#include "Input/Input.h"
#include "Resources/ResourceManager.h"
#include "Render/Render.h"

int main()
{
	INFO("antEngine был запущен");
	
	// Инициализация основных подсистем движка
	Resources::ResourceManager::Instance().Init();
	Audio::AudioPlayer::Instance().Init();
	Render::Render::Instance().Init();
	Gameplay::Gameplay::Instance().Init();
	Input::Input::Instance().Init();
	//ScriptManager.Init();
	
	Audio::AudioPlayer::Instance().PlayMusic(Resources::ResourceManager::Instance().GetMusicByName("Music0"), false);
	
	// Для замера производительности
	float fps;
	sf::Clock clock;
	sf::Time  previousTime;
	sf::Time  currentTime;
	
	while(Gameplay::Gameplay::Instance().IsRun())
	{
#ifdef _DEBUG
		previousTime = clock.getElapsedTime();
#endif

		Input::Input::Instance().OnFrame();
		Gameplay::Gameplay::Instance().OnFrame();
		Render::Render::Instance().OnFrame();

#ifdef _DEBUG
		currentTime = clock.getElapsedTime();
		fps = 1.0f / (currentTime.asSeconds() - previousTime.asSeconds());
		std::cout << "fps = " << floor(fps) << std::endl;
		previousTime = currentTime;
#endif
	}
	
	Render::Render::Instance().Deinit();
	INFO("antEngine прекратил свою работу");
}