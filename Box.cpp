#include "Box.h"
#include "Framework/Headers/AssetManager.h"

Box::Box()
	: GridObject()
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/Box.png"));
	m_blocksMovement = true;
}
