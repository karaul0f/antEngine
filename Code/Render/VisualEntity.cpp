#include "VisualEntity.h"

#include "Resources/ResourceManager.h"

namespace Render
{
//-----------------------------------------------------------------
VisualEntity::VisualEntity()
{
	m_isActive = true;

	m_texture = &Resources::ResourceManager::Instance().GetTexureByName("Sprite0");
	m_sprite.setTexture(*m_texture);
	m_sprite.setTextureRect(sf::IntRect(0, 0, m_texture->getSize().x, m_texture->getSize().y));
}
//-----------------------------------------------------------------
void VisualEntity::SetPosition(int x, int y)
{
	m_sprite.setPosition(x, y);
}
//-----------------------------------------------------------------
sf::Drawable& VisualEntity::GetDrawable()
{
	return m_sprite;
}
//-----------------------------------------------------------------
}
