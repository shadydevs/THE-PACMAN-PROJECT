#include "Pacman.h"

Pacman::Pacman()
{
	tL.loadFromFile("data/bagPac/pacman-left.png");				//initial position texture
	tR.loadFromFile("data/bagPac/pacman-right.png");
	tU.loadFromFile("data/bagPac/pacman-up.png");
	tD.loadFromFile("data/bagPac/pacman-down.png");
	pacman.setTexture(&tL);
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

//RectangleShape Pacman::getPacmanShape()
//{
//	return pacman;
//}
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

//void Pacman::checkPellets()
//{
//	if (eatenPellets == 150)
//		//you won!
//}
void Pacman::movePacman(int bitmap[21][19])
{
	//switch (direction)
	//{
	//case 'L':
	//	//if (bitmap[posI][posJ - 1] != -1)
	//	//{
	//		this->direction = Vector2i(-1, 0);		
	//		//posJ--;
	//	//}
	//	break;
	//case 'R':
	//	//if (bitmap[posI][posJ + 1] != -1)
	//	//{
	//		this->direction = Vector2i(1, 0);
	//		//posJ++;
	//	//}
	//	break;
	//case 'U':
	//	//if (bitmap[posI - 1][posJ] != -1)
	//	//{
	//		this->direction = Vector2i(0, -1);
	//		//posI--;
	//	//}
	//	break;
	//case 'D':
	//	//if (bitmap[posI + 1][posJ] != -1)
	//	//{
	//		this->direction = Vector2i(0, 1);
	//		//posI++;
	//	//}
	//	break;
	//default:
	//	break;
	//}
	
	//usage of (this.) as function parameter has same name
	if (bitmap[posI + direction.y][posJ + direction.x] != -1)
	{
		pacman.move(37.5 * direction.x, 37.5 * direction.y);
		posI = posI + direction.y;
		posJ = posJ + direction.x;
	}
}

//error
void Pacman::eat(ghost g)
{
	for (int i = 0; i < 4; i++)
	{
		if (pacman.getGlobalBounds().intersects(g.ghosts[i].getGlobalBounds()))
		{
			if (superModeOn)
			{
				g.ghosts[i].setPosition(g.startPosition[i]);

				//if pacman is in fright mode
				score = score + 200 * eatenGhosts;//200 for first, 400 for second, 800 for third, 1600 for forth
				updateScore();
				eatenGhosts++;
			}
			else
			{
				lives--;
				updateLives();
				pacman.setPosition(292, 527); // return to initial position

			}
		}
	}
}

	//if (collide(this, g) == 1)			//An object of class pacman and an object of class ghost are given as parameters
	//{
	//	g.ghosts[i].setPosition(g.startPosition[i]);

	//	//if pacman is in fright mode
	//	score = score + 200 * eatenGhosts;//200 for first, 400 for second, 800 for third, 1600 for forth
	//	updateScore();
	//	eatenGhosts++;
	//}
	//else if (collide(this, g) == 2)
	//{
	//	lives--;
	//	updateLives();
	//	pacman.setPosition(292, 527); // return to initial position
	//}

//}
////call updateLives
////operator overloading in lives--
//}


void Pacman::eatPellet(int bitmap[][19], Sprite mazeSprites[][19])
{
	if (bitmap[posI][posJ] == 1)
	{
		bitmap[posI][posJ] = 0;
		eatenPellets++;
		score = score + 10;
		updateScore();
		mazeSprites[posI][posJ].setColor(Color::Black);
		if (eatenPellets == 150)
			cout << "You won!";
	}
	else if(bitmap[posI][posJ] == 2)
	{
		bitmap[posI][posJ] = 0;
		eatenPellets++;
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
