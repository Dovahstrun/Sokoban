//Library Includes
#include <iostream>
#include <fstream>

//Project Includes

#include "Level.h"

Level::Level()
	: m_player(nullptr)
	, m_updateList()
	, m_drawSpriteList()
	, m_drawUIList()
	, m_collisionList()
	, m_currentLevel(0)
{
	loadLevel(1);
}

void Level::Draw(sf::RenderTarget & _target)
{
	//Create and update camera
	sf::View camera = _target.getDefaultView();
	camera.setCenter(m_player->GetPosition());
	//TODO: Follow player with camera

	// Draw game world to the window
	_target.setView(camera);
	//Draw game objects
	for (int i = 0; i < m_drawSpriteList.size(); ++i)
	{
		if (m_drawSpriteList[i]->isActive())
		{
			m_drawSpriteList[i]->Draw(_target);
		}
	}



	// Draw UI to the window
	_target.setView(_target.getDefaultView());
	//Draw UI objects
	for (int i = 0; i < m_drawUIList.size(); ++i)
	{
		if (m_drawUIList[i]->isActive())
		{
			m_drawUIList[i]->Draw(_target);
		}
	}
}

void Level::Update(sf::Time _frameTime)
{
	//Update
	for (int i = 0; i < m_updateList.size(); ++i)
	{
		if (m_updateList[i]->isActive())
		{
			m_updateList[i]->Update(_frameTime);
		}
	}


	// -----------------------------------------------
	// Collision Section
	// -----------------------------------------------

	for (int i = 0; i < m_collisionList.size(); ++i)
	{
		GameObject* handler = m_collisionList[i].first;
		GameObject* collider = m_collisionList[i].second;


		if (handler->isActive() && collider->isActive())
		{
			if (handler->GetBounds().intersects(collider->GetBounds()))
			{
				handler->Collide(*collider);
			}
		}
	}
}

void Level::loadLevel(int _levelToLoad)
{

	///Cleanup the old level

	//Delete any data already in the level
	for (int i = 0; i < m_updateList.size(); ++i)
	{
		delete m_updateList[i];
	}

	//FUCKING THING NOT WORKING, DELETE IS BREAKING IT, REMEMBER THIS FUCKING THING FOR GODS SAKE OH MY GOD

	//Clear out the lists
	m_updateList.clear();
	m_drawSpriteList.clear();
	m_drawUIList.clear();
	m_collisionList.clear();

	///Setup everything

	//Set current level
	m_currentLevel = _levelToLoad;

	//Set up all the game objects

	//Close the file now that we're done
	
}

void Level::ReloadLevel()
{
	loadLevel(m_currentLevel);
}

int Level::GetCurrentLevel()
{
	return m_currentLevel;
}
