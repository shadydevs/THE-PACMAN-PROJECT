#include "Pacman.h"

Pacman::Pacman()
{
	spriteSheet.loadFromFile("data/pacman.png");
	pacman.setTexture(&spriteSheet);
	posI = 15; //This is the initial position of pacman
	posJ = 9; 
	pacman.setSize(Vector2f(25, 26.25));
	pacman.setPosition(posJ * 37.5f + 7, posI * 37.5f + 7 + (37.5f * 2.0f));
	direction = Vector2i(0, 0);
	score = 0;
	eatenPellets = 0;
	lives = 3;
	superModeOn = false;
}

int Pacman::getScore()
{
	return score;
}
void Pacman::updateScore()
{
	if (score >= 10000)
		lives++;
}
int Pacman::getLives()
{
	return lives;
}
void Pacman::updateLives()
{
	if (lives < 1)
	{
		cout << "You lost!";
		pacman.setPosition(0, 0);
		pacman.setFillColor(Color::Black);
	}
}

void Pacman::movePacman(int bitmap[21][19])
{
	if (bitmap[posI + direction.y][posJ + direction.x] != -1)
	{
		pacman.move(37.5 * direction.x, 37.5 * direction.y);
		posI = posI + direction.y;
		posJ = posJ + direction.x;
	}
	if (posI == 9 && posJ == 0)
	{
		posI = 9;
		posJ = 18;
		pacman.setPosition(posJ * 37.5f + 7, posI * 37.5f + 7 + (37.5f * 2.0f));
	}
	else if (posI == 9 && posJ == 18)
	{
		posI = 9;
		posJ = 0;
		pacman.setPosition(posJ * 37.5f + 7, posI * 37.5f + 7 + (37.5f * 2.0f));
	}
}

void Pacman::eat(ghost& g, int i)
{
	if (superModeOn)	//if pacman is in fright mode
	{
		g.posIs[i] = 7; g.posJs[i] = 9;
		g.ghosts[i].setPosition(Vector2f(g.posJs[i] * 37.5 + (18.75f - 7.5f), g.posIs[i] * 37.5 + (18.75f - 7.5) + (37.5f * 2.0f)));
		score = score + 200 * eatenGhosts;//200 for first, 400 for second, 800 for third, 1600 for forth
		updateScore();
		eatenGhosts++;
	}
	else
	{
		lives--;
		updateLives();
		// return to initial position
		posI = 15; //This is the initial position of pacman
		posJ = 9;
		pacman.setPosition(posJ * 37.5f + 7, posI * 37.5f + 7 + (37.5f * 2.0f));
		direction = Vector2i(0, 0);
	}
}

void Pacman::eat(int bitmap[][19], Sprite mazeSprites[][19])
{
	if (bitmap[posI][posJ] == 1)
	{
		bitmap[posI][posJ] = 0;
		eatenPellets++;
		if (eatenPellets == 150)
			cout << "You won!";
		score += 10;
		updateScore();
		mazeSprites[posI][posJ].setColor(Color::Black);
	}
	else if(bitmap[posI][posJ] == 2)
	{
		bitmap[posI][posJ] = 0;
		eatenPellets++;
		if (eatenPellets == 150)
			cout << "You won!";
		score = score + 50;
		updateScore();
		superModeOn = true;
		mazeSprites[posI][posJ].setColor(Color::Black);
	}
}

int Pacman::getposI()
{
	return posI;
}
void Pacman::setposI(int i)
{
	posI = i;
}
int Pacman::getposJ()
{
	return posJ;
}
void Pacman::setposJ(int j)
{
	posJ = j;
}
