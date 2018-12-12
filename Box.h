#pragma once

#pragma once

#include "GridObject.h"

class Box : public GridObject
{

public:

	Box();

	bool AttemptPush(sf::Vector2i _direction);

private:

	sf::Sound m_pushed;

};