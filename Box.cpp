#include "Box.h"
#include "Framework/Headers/AssetManager.h"
#include "Level.h"

Box::Box()
	: GridObject()
	, m_pushed()
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/Box.png"));
	m_blocksMovement = true;
	m_pushed.setBuffer(AssetManager::GetSoundBuffer("audio/push.wav"));
}

bool Box::AttemptPush(sf::Vector2i _direction)
{
	///Attempt to move the box in the given direction

	//Get your current position
	//Calculate target position
	sf::Vector2i targetPos = m_gridPosition + _direction;

	//Check if the space is empty
	//Get list of objects in target position (targetpos)
	std::vector<GridObject*> targetCellContents = m_level->getObjectAt(targetPos);
	//Check if any of those objects block movement
	bool blocked = false;
	for (int i = 0; i < targetCellContents.size(); ++i)
	{
		if (targetCellContents[i]->getBlocksMovement() == true)
		{
			blocked = true;

		}
	}

	//If empty move there
	

	if (!blocked)
	{
		m_pushed.play();
		return m_level->MoveObjectTo(this, targetPos);
	}

	//If movement is blocked, do nothing, return false
	//m_bump.play();
	return false;
}

