#include "ghost.h"

void ghost::BFS(int src)
{

}

ghost::ghost()
{
	posIs[0] = 7; posJs[0] = 9;
	posIs[1] = 9; posJs[1] = 10;
	posIs[2] = 9; posJs[2] = 9;
	posIs[3] = 9; posJs[3] = 8;

	direction[0] = Vector2i(-1, 0);
	for (int i = 1; i < 4; i++)
	{
		direction[i] = Vector2i(0, 0);
		startPosition[i] = Vector2f(posJs[i] * 37.5 + (18.75f - 7.5f), posIs[i] * 37.5 + (18.75f - 7.5) + (37.5f * 2.0f));
	}

	getOutScore[0] = 0;			//blinky gets out immediately
	getOutScore[1] = 50;		//pinky gets out right after blinky so low get out score required
	getOutScore[2] = 500;
	getOutScore[3] = 750;
}

void ghost::setghosts()
{
	//i and j for he array 

	blinkyT.loadFromFile("data/blinky.jpeg");
	inkyT.loadFromFile("data/inky.jpeg");
	clydeT.loadFromFile("data/clyde.jpeg");
	pinkyT.loadFromFile("data/pinky.jpeg");
	ghosts[0].setTexture(blinkyT);
	ghosts[1].setTexture(pinkyT);
	ghosts[2].setTexture(inkyT);
	ghosts[3].setTexture(clydeT);

	for (int i = 0; i < 4; i++)
	{
		ghosts[i].setPosition(posJs[i] * 37.5 + (18.75f - 7.5f), posIs[i] * 37.5 + (18.75f - 7.5) + (37.5f * 2.0f));
	}
}

void ghost::moveGhost(int bitmap[21][19]) {
	for (int i = 0; i < 4; i++)
	{
		if (bitmap[posIs[i] + direction[i].y][posJs[i] + direction[i].x] != -1)
		{
			ghosts[i].move(37.5 * direction[i].x, 37.5 * direction[i].y);
			posIs[i] = posIs[i] + direction[i].y;
			posJs[i] = posJs[i] + direction[i].x;
		}
	}
}