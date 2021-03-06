#include "Level.h"

namespace Gameplay
{
//-----------------------------------------------------------------
void Level::Activate()
{
	m_entities.emplace_back();
	m_entities[0].Activate();
}
//-----------------------------------------------------------------
void Level::OnFrame()
{
	for (auto& entity : m_entities)
	{
		if(entity.IsActive())
			entity.OnFrame();
	}
}
//-----------------------------------------------------------------
void Level::Deactivate()
{
	m_entities.clear();
}
//-----------------------------------------------------------------
}