#include "Entity.h"

namespace Gameplay
{
//-----------------------------------------------------------------
Entity::Entity()
{
	m_isActive = true;
}
//-----------------------------------------------------------------
bool Entity::IsActive()
{
	return m_isActive;
}
//-----------------------------------------------------------------
void Entity::OnFrame()
{
	for(auto component: m_components)
		component->OnFrame();
}
//-----------------------------------------------------------------
}