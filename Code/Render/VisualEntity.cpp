#include "VisualEntity.h"

namespace Render
{
//-----------------------------------------------------------------
VisualEntity::VisualEntity()
{
	m_isActive = true;
	//m_sprite = ((IVisualResource*)Resources::ResourceManager::Instance()->GetResourceByName(std::string name))->GetSprite();
	m_texture.loadFromFile("Data/Resources/DefaultSprite.png");

	m_sprite.setTexture(m_texture);
	m_sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
	m_sprite.setPosition(50, 25);
}
//-----------------------------------------------------------------
sf::Drawable& VisualEntity::GetDrawable()
{
	return m_sprite;
}
//-----------------------------------------------------------------
}