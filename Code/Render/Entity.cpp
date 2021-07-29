#include "Entity.h"

namespace Render
{
//-----------------------------------------------------------------
Entity::Entity()
{
	m_isActive = true;

	m_texture.loadFromFile("Data/Resources/DefaultSprite.png");

	m_sprite.setTexture(m_texture);
	m_sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
	m_sprite.setPosition(50, 25);
}
//-----------------------------------------------------------------
bool Entity::IsActive()
{
	return m_isActive;
}
//-----------------------------------------------------------------
void Entity::SetX(int x)
{
	m_x = x;
}
//-----------------------------------------------------------------
void Entity::SetY(int y)
{
	m_y = y;
}
//-----------------------------------------------------------------
sf::Drawable& Entity::GetDrawable()
{
	return m_sprite;
}
//-----------------------------------------------------------------
}