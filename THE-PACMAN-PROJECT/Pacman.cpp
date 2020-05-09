#include "Pacman.h"

Pacman::Pacman()
{
	t.loadFromFile("data/pacman.png");
	pacman.setTexture(t);
	posI = 15; //This is the initial position of pacman
	posJ = 9; 
	pacman.setPosition(posJ * 37.5f + 7, posI * 37.5f + 7 + (37.5f * 2.0f));
	score = 0;
	eatenPellets = 0;
	lives = 3;
}

Sprite Pacman::getPacmanSprite()
{
	return pacman;
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
		pacman.setColor(Color::Black);
	}
}
//void Pacman::checkPellets()
//{
//	if (eatenPellets == 150)
//		//you won!
//}
void Pacman::movePacman(char direction, int bitmap[][19])
{
	switch (direction)
	{
	case 'L':
		if (bitmap[posI][posJ-1] != -1)
		{
			pacman.move(-37.5, 0);
			posJ--;
		}
		break;
	case 'R':
		if (bitmap[posI][posJ +1] != -1)
		{
			pacman.move(37.5, 0);
			posJ++;
		}
		break;
	case 'U':
		if (bitmap[posI -1][posJ] != -1)
		{
			pacman.move(0, -37.5);
			posI--;
		}
		break;
	case 'D':
		if (bitmap[posI +1][posJ] != -1)
		{
			pacman.move(0, 37.5);
			posI++;
		}
		break;
	default:
		break;
	}
}
//void Pacman::eat(ghost g[])
//{
//	for (int i = 0; i < 4; i++)
//	{
//		if (collide(pac, g[i]) == 1) //An object of class pacman and an object of class ghost are given as parameters
//		{
//			g[i].ghost.setPosition(g[i].getstartPosition())
//
//				//if pacman is in fright mode
//				score = score + 200 * countGhosts;//200 for first, 400 for second, 800 for third, 1600 for forth
//			check_score(score);
//			countGhosts++;
//		}
//		else if (collide(pac, g[i]) == 2)
//		{
//			lives--;
//			update_lives();
//			pacman.setPosition(292, 527); // return to initial position
//		}
//
//	}
//call updateLives
//operator overloading in lives--
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
}