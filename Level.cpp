//Library Includes
#include <iostream>
#include <fstream>

//Project Includes

#include "Level.h"

Level::Level()
	: m_currentLevel(0)
{
	loadLevel(1);
}

void Level::Draw(sf::RenderTarget & _target)
{
	//Create and update camera
	sf::View camera = _target.getDefaultView();
	//TODO:Adjust camera

	_target.setView(camera);
	//TODO

	//Draw game objects
	//TODO



	// Draw UI to the window
	_target.setView(_target.getDefaultView());
	//Draw UI objects
	//TODO
}

void Level::Update(sf::Time _frameTime)
{
	
}

void Level::loadLevel(int _levelToLoad)
{

	///Cleanup the old level

	//Delete any data already in the level
	//TODO

	//FUCKING THING NOT WORKING, DELETE IS BREAKING IT, REMEMBER THIS FUCKING THING FOR GODS SAKE OH MY GOD

	//Clear out the lists
	//TODO

	///Setup everything

	//Set current level
	m_currentLevel = _levelToLoad;

	//Set up all the game objects
	//Open our file for reading
	std::ifstream inFile;
	std::string fileName = "levels/Level" + std::to_string(m_currentLevel) + ".txt";
	inFile.open(fileName);

	//Make sure the file was opened
	if (!inFile)
	{
		std::cerr << "Unable to open file " + fileName;
		exit(1); //Call system to stop program with error	
	}

	//Set the starting x and y coords used to position level objects
	float x = 0.0f;
	float y = 0.0f;

	//Define the spacing we will use for our grid
	const float Y_SPACE = 100.0f;
	const float X_SPACE = 100.0f;

	//Reading each character one by one from the file...
	char ch;
	//Each time, try to read the next character, execute body of loop
	while (inFile >> std::noskipws >> ch)//the noskipws means we will include the white space (spaces)
	{
		//Perform actions based on what character was read in
		if (ch == ' ')
		{
			x += X_SPACE;
		}
		else if (ch == '\n')
		{
			y += Y_SPACE;
			x = 0;
		}
		else
		{
			std::cerr << "Unrecognised character in level file: " << ch;
		}
	}

	//Close the file now that we're done
	inFile.close();

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
