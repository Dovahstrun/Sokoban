#pragma once

//Library Includes
#include <SFML/Graphics.hpp>

class Level
{

public:

	Level();

	virtual void Draw(sf::RenderTarget& _target);
	virtual void Update(sf::Time _frameTime);

	void loadLevel(int _levelToLoad);
	void ReloadLevel();
	int GetCurrentLevel();

private:

	const float m_cellSize;
	int m_currentLevel;
	std::vector<std::vector<sf::Sprite>> m_background;
};
