#pragma once

#pragma once

#include "GridObject.h"

class Box : public GridObject
{

public:

	Box();

	bool AttemptPush(sf::Vector2i _direction);
	bool getStored();

private:

	bool m_stored;
	sf::Sound m_pushed;
	sf::Sound m_storeSound;

};