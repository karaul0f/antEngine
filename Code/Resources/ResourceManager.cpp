#include "ResourceManager.h"
#include "../Core/Logger.h"
#include "tinyxml2.h"
#include "tinyxml2.cpp"

namespace
{
	const std::string SPRITE_TYPE = "Sprite";
	const std::string MUSIC_TYPE = "Music";
	const std::string SOUND_TYPE = "Sound";
}

namespace Resources
{
//-----------------------------------------------------------------
void ResourceManager::Init()
{
	INFO("Инициализация менеджера ресурсов");
	ResourceLoad();
	
}
//-----------------------------------------------------------------
void ResourceManager::Deinit()
{
	
}
void ResourceManager::ResourceLoad()
{
	tinyxml2::XMLDocument doc;
	doc.LoadFile("Data/GameConfig.xml");

	tinyxml2::XMLElement* gameConfigElement = doc.FirstChildElement("GameConfig");
	if (gameConfigElement != nullptr) 
	{
		tinyxml2::XMLElement* resources = gameConfigElement->FirstChildElement("Resources");

		for (tinyxml2::XMLElement* resource = resources->FirstChildElement("Resource");
			resource != nullptr; resource = resource->NextSiblingElement())
		{
			if (SPRITE_TYPE == resource->Attribute("Type")) //SPRITE_TYPE.compare(resource->Attribute("Type"))
			{
				m_textures[resource->Attribute("Name")].loadFromFile(CreatePath(resource->Attribute("Path")));
				m_sprites[resource->Attribute("Name")].setTexture(m_textures[resource->Attribute("Name")]);
			}
			else if (MUSIC_TYPE == resource->Attribute("Type"))
			{
				m_musics[resource->Attribute("Name")].openFromFile(CreatePath(resource->Attribute("Path")));
			}
			else if (SOUND_TYPE == resource->Attribute("Type"))
			{
				m_soundBuffers[resource->Attribute("Name")].loadFromFile(CreatePath(resource->Attribute("Path")));
				m_sounds[resource->Attribute("Name")].setBuffer(m_soundBuffers[resource->Attribute("Name")]);
			}
		}
	}
}
std::string ResourceManager::CreatePath(std::string path)
{
	path = "Data/Resources/" + path;
	return path;
}
sf::Sprite& ResourceManager::GetSpriteByName(std::string name)
{
	return m_sprites[name];
}
sf::Music& ResourceManager::GetMusicByName(std::string name)
{
	return m_musics[name];
}
sf::Sound& ResourceManager::GetSoundByName(std::string name)
{
	return m_sounds[name];
}
//-----------------------------------------------------------------
}
