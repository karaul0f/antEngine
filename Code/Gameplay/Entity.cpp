#include "Entity.h"
#include "Components/GraphicComponent.h"

namespace Gameplay
{
//-----------------------------------------------------------------
Entity::Entity()
{
	m_components.push_back(std::make_unique<GraphicComponent>());
}
//-----------------------------------------------------------------
bool Entity::IsActive()
{
	return m_isActive;
}
//-----------------------------------------------------------------
void Entity::OnFrame()
{
	for(auto& component: m_components)
		component->OnFrame();
}
//-----------------------------------------------------------------
void Entity::Activate()
{
	m_isActive = true;
	
	for (auto& component : m_components)
		component->Activate();
}
//-----------------------------------------------------------------
void Entity::Deactivate()
{
	m_isActive = false;
	m_components.clear();
}
//-----------------------------------------------------------------
}
