#include <SFML/Graphics.hpp>
#include "ghost.h"

class Pacman
{
private:
	int score, lives;
	int posI, posJ;
public:
	Texture spriteSheet;
	Texture tL;
	Texture tR;
	Texture tU;
	Texture tD;

	Vector2i direction;			//direction of movement
	RectangleShape pacman;		//shape used for pacman

	int eatenGhosts, eatenPellets;
	bool superModeOn;

	Pacman();
	
	int getposI();
	void setposI(int i);
	int getposJ();
	void setposJ(int j);

	int getScore();
	void updateScore();
	int getLives();
	void eatPellet(int bitmap[][19], Sprite mazeSprites[][19]);
	void updateLives();
	void movePacman(int bitmap[21][19]);
	void eat(ghost& g, int i);
};