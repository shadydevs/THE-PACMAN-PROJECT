#pragma once
#include <iostream>
#include <fstream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Character.h"
using namespace sf;
using namespace std;

class Pacman : public Character
{
private:
	int score, lives;
public:
	Vector2i direction;			//direction of movement
	RectangleShape pacman;		//shape used for pacman

	Pacman();
	int eatenGhosts, eatenPellets;
	
	int getScore();
	void updateScore();
	int getLives();
	void eatPellet(int bitmap[][19], Sprite mazeSprites[][19]);
	void updateLives();

	//RectangleShape getPacmanShape();
	void movePacman(int bitmap[21][19]);
	//void eat(ghost g);
	//void eat(pellet pell);
};