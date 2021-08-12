#include "GraphicComponent.h"

#include "Render/Render.h"

namespace Gameplay
{
//-----------------------------------------------------------------
void GraphicComponent::Activate()
{
	Render::Render::Instance().CreateEntity();
}
//-----------------------------------------------------------------
void GraphicComponent::Deactivate()
{
	
}
//-----------------------------------------------------------------
void GraphicComponent::OnFrame()
{
	
}
//-----------------------------------------------------------------
}
