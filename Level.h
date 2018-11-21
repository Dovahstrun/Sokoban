#pragma once

//Library Includes
#include <SFML/Graphics.hpp>
#include "GridObject.h"

class Level
{

public:

	Level();

	virtual void Draw(sf::RenderTarget& _target);
	virtual void Update(sf::Time _frameTime);

	void loadLevel(int _levelToLoad);
	void ReloadLevel();
	int GetCurrentLevel();

	int getCellSize();

private:

	const float m_cellSize;
	int m_currentLevel;
	std::vector<std::vector<sf::Sprite> > m_background;
	std::vector<std::vector<std::vector<GridObject*> > > m_contents;
};
