#include "Pacman.h"

Pacman::Pacman() {
	t.loadFromFile("data/pacman-left.png");
	pacman.setTexture(t);
	posI = 15; //This is the initial position of pacman
	posJ = 9; 
	pacman.setPosition(posJ * 37.5f + 7, posI * 37.5f + 7 + (37.5f * 2.0f));
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
//void Pacman::updateLives()
//{
//	if (lives < 1)
//		// game over
//}
//void Pacman::checkPellets()
//{
//	if (eatenPellets == )
//		//you won!
//}
void Pacman::movePacman(char direction, int bitmap[][19])
{
	switch (direction)
	{
	case 'L':
		if (bitmap[posI][posJ +1] != -1)
		{
			cout << "Pacman left";
			pacman.move(-37.5, 0);
			posJ--;
		}
		break;
	case 'R':
		if (bitmap[posI][posJ -1] != -1)
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
//}
//void Pacman::eat(pellet pell)
//{
//	if (collide(pac, pell) && (!pell.isEaten)) //check this
//	{
//		//I assummed that in the pellet structure, there is a boolean variable called power
//		if (pell.power == true) //object is in fright mode
//		{
//			score = score + 50;
//			updateScore();
//			//remove pellet, make it an empty space
//		}
//		else
//		{
//score = score + 10;
//			updateScore();
//			pell.pellet.setColor(Color::Black);
//			//remove pellet, make it an empty space
//		}
//		eatenPellets++;
//		pell.isEaten = true;
//	}
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
	}
}

////int main()
////{
////	pacman pac;
////	const int rows = 10;
////	const int columns = 10;
////	int array[rows][columns];
////	Sprite maze[rows][columns];
////
////	// Create the main window
////	RenderWindow game(Videomode(800, 600), "Pacman");
////
////	//declare all of my variables that I need. Do any initializations here.

////	// Start the game loop -- this is where my logic happens
////	while (game.isOpen())
////	{
////		// Process events
////		Event event;
////
////		while (game.pollEvent(event))
////		{
////			//if my user pressed a button on their keyboard
////			if (event.type == Event::KeyPressed)
////			
////			}
////		}
////		// CLear screen
////		game.clear();
////		// Draw any of the things that I declared to the screen that I want to be visible
////		game.draw(pac.getPacmanSprite());
////		// Update the window
////		game.display();
////	}
////	return 0;
////}