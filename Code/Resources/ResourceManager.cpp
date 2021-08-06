#include "ResourceManager.h"
#include "../Core/Logger.h"
#include "tinyxml2.h"
#include "tinyxml2.cpp"

namespace
{
	const std::string SPRITE_TYPE = "Sprite";
	const std::string MUSIC_TYPE = "Music";
	const std::string SOUND_TYPE = "Sound";
	const std::string PATH_TO_RESOURCES = "Data/Resources/";
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
	m_textures.clear();
	m_musics.clear();
	m_soundBuffers.clear();
}
//-----------------------------------------------------------------
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
			if (SPRITE_TYPE == resource->Attribute("Type"))
			{
				m_textures[resource->Attribute("Name")].loadFromFile(CreatePath(resource->Attribute("Path")));
			}
			else if (MUSIC_TYPE == resource->Attribute("Type"))
			{
				m_musics.try_emplace(resource->Attribute("Name"), CreatePath(resource->Attribute("Path")));
			}
			else if (SOUND_TYPE == resource->Attribute("Type"))
			{
				m_soundBuffers[resource->Attribute("Name")].loadFromFile(CreatePath(resource->Attribute("Path")));
				m_sounds.try_emplace(resource->Attribute("Name"), CreatePath(resource->Attribute("Path")), m_soundBuffers[resource->Attribute("Name")]);
			}
		}
	}
}
//-----------------------------------------------------------------
std::string ResourceManager::CreatePath(const std::string& path)
{
	return PATH_TO_RESOURCES + path;
}
//-----------------------------------------------------------------
sf::Texture& ResourceManager::GetTexureByName(const std::string& name)
{
	return m_textures[name];
}
//-----------------------------------------------------------------
Music& ResourceManager::GetMusicByName(const std::string& name)
{
	return m_musics[name];
}
//-----------------------------------------------------------------
Sound& ResourceManager::GetSoundByName(const std::string& name)
{
	return m_sounds[name];
}
//-----------------------------------------------------------------
}
