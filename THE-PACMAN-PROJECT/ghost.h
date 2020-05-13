#include <SFML/Graphics.hpp>
#include <queue>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace sf;
using namespace std;
class ghost
{
private:
	Sprite blinky, pinky, inky, clyde;
	Texture blinkyT, pinkyT, inkyT, clydeT;


public:
	int getOutScore[4];			//the score pac reaches when each ghost gets out of home
	int AdjList[21][19];
	int grid[21][19];
	void matrix();

	Sprite ghosts[4] = { blinky, pinky, inky, clyde };
	Vector2i direction[4];
	Vector2f startPosition[4];
	int posIs[4];
	int posJs[4];
	ghost();

	void setghosts();
	void moveGhost(int bitmap[21][19]);
	//vector<int>* AdjList;//vector
	//void BFS(int src);
	//void Graph(const int& p_Vertices);
};

void do_bfs(ghost* gh, int, int);