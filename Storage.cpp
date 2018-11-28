// Project Includes
#include "Storage.h"
#include "Framework/Headers/AssetManager.h"

Storage::Storage()
	: GridObject()
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/storage.png"));
}