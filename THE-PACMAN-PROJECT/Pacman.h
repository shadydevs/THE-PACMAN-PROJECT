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
	Sprite pacman;

	Pacman();
	int eatenGhosts, eatenPellets;
	
	int getScore();
	void updateScore();
	int getLives();
	void eatPellet(int bitmap[][19], Sprite mazeSprites[][19]);
	void updateLives();

	Sprite getPacmanSprite();
	void movePacman(char direction, int bitmap[21][19]);
	//void eat(ghost g);
	//void eat(pellet pell);
};