#include "Box.h"
#include "Framework/Headers/AssetManager.h"
#include "Level.h"
#include "Storage.h"

Box::Box()
	: GridObject()
	, m_stored(false)
	, m_pushed()
	, m_storeSound()
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/Box.png"));
	m_blocksMovement = true;
	m_pushed.setBuffer(AssetManager::GetSoundBuffer("audio/push.wav"));
	m_storeSound.setBuffer(AssetManager::GetSoundBuffer("audio/stored.wav"));
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
		bool moveSucceeded =  m_level->MoveObjectTo(this, targetPos);

		//If we DID successfully move
		if (moveSucceeded)
		{
			//Check if we are stored
			m_stored = false;

			//Loop through the contents and see if a storage object was found
			for (int i = 0; i < targetCellContents.size(); ++i)
			{
				Storage* storageObject = dynamic_cast<Storage*>(targetCellContents[i]);

				//If dynamic cast succeeds, it will NOT be a nullptr (it is a storage object
				if (storageObject != nullptr)
				{
					//The object is a storage object

					//We are stored
					m_stored = true;
					m_storeSound.play();
				}
			}

			//If we are, update our bool amd change our sprite
			if (m_stored)
			{
				m_sprite.setTexture(AssetManager::GetTexture("graphics/boxStored.png"));
			}
			else
			{
				m_sprite.setTexture(AssetManager::GetTexture("graphics/Box.png"));
			}
		}

		return moveSucceeded;
	}

	//If movement is blocked, do nothing, return false
	//m_bump.play();
	return false;
}

bool Box::getStored()
{
	return false;
}

