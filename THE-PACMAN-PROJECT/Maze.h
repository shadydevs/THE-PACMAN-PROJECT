#pragma once
#include "SFML/Graphics.hpp"
#include "Pacman.h"
#include<iostream>
#include<fstream>
#include<string>

using namespace std;
using namespace sf;

const int sizex = 19, sizey = 21;
int bitmap[sizey][sizex];
class Maze
{
private:
	ifstream bitmapFile;
	Pacman& pac;
	Texture pelletT;
	Texture tileT;
public:
	/*int bitmap[sizey][sizex];*/
	Maze(string, string, string, Pacman& _pac);
	Sprite mazeSprites[sizey][sizex];
};

