#include "ghost.h"
#define MAX 99999

void ghost::matrix()
{
	//int Adjlist[21][19];
	ifstream in_file;
	in_file.open("graph.txt");
	for (int i = 0; i < 21; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			in_file >> AdjList[i][j];
			if (AdjList[i][j] == -1)
				grid[i][j] = -1;
			else
				grid[i][j] = 0;
		}
	}
	in_file.close();
	//for (int i = 0; i < 21; ++i)
	//{
	//	for (int j = 0; j < 19; ++j)
	//	{
	//		cout << grid[i][j];
	//	}
	//
}
//Basic point struct
struct basicPoint
{
	int x;
	int y;

	//Struct constructor
	basicPoint(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	//Method to check two points for equality
	bool equals(basicPoint* otherPoint)
	{
		return (this->x == otherPoint->x && this->y == otherPoint->y);
	}
};

//BFS
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

void do_bfs(ghost* gh, int initialPacmanX, int initialPacmanY)
{
	//Initialise queue and obtain the actual play grid
	std::queue<basicPoint> queue;
	/*int playGrid[][] = functionToGetGrid();*/

	//matrix();
	// initialize grid with values corresponding to walls or INT.MAX_VALUE
	/*int grid[][];*/

	// add starting position of pacman to queue
	basicPoint pacmanPos = basicPoint(initialPacmanX, initialPacmanY);
	queue.push(pacmanPos);

	while (!queue.empty())
	{
		// remove and access first element
		basicPoint cur_place = queue.front();
		queue.pop();
		int cur_x = cur_place.x;
		int cur_y = cur_place.y;
		int cur_distance = gh->grid[cur_x][cur_y];

		for (int i = 0; i < 4; i++)
		{
			if (gh->grid[cur_x + dx[i]][cur_y + dy[i]] != MAX)
				//if (cur_x + dx[i] >= 0 && gh->grid[i][j]!=-1)//define 2arrau
			{
				basicPoint currentPoint = basicPoint(cur_x + dx[i], cur_y + dy[i]);
				queue.push(currentPoint);
				gh->grid[cur_x + dx[i]][cur_y + dy[i]] = cur_distance + 1;
			}
		}
	}
	int v = MAX;
	basicPoint initialpost = basicPoint(gh->posIs[0], gh->posJs[0]);    //orginal position of ghost
	for (int i = 0; i < 4; i++)
	{
		if (gh->grid[gh->posIs[0] + dx[i]][gh->posJs[0] + dy[i]] != -1);
		{
			if (gh->grid[gh->posIs[0] + dx[i]][gh->posJs[0] + dy[i]] < v)
			{
				v = gh->grid[gh->posIs[0] + dx[i]][gh->posJs[0] + dy[i]];
				initialpost.x = gh->posIs[0] + dx[i];
				initialpost.y = gh->posJs[0] + dy[i];
			}
			//call moveghost
			gh->ghosts[0].move(37.5 * dx[i], 37.5 * dy[i]);
		}
		// now grid is filled, so now you should find out for each ghost how to move
	}
}
////void ghost::BFS(int srcx,int srcy)
////{
////	cout << "Breadth-First Search.\n";
////	queue<int> q;
////	ghost[i].posI;
////	ghost[i].posJ;
////	//vector<bool> visited(Vertices, false);
////	bool visited[21][19];
////	for (int i = 0; i <= 21; i++) 
////	{
////		for (int j = 0; j < 19; j++) 
////		{visited[]i[j]=false}
////	}
////	q.push(src);
////	visited[srcx][srcy] = true;
////	vector<int>::iterator i;
////	while (!q.empty())// will the condition here change to while(position of ghost is not positiion of the next cell??)
////	{int u = q.front();//what does the  u do?
////		q.pop();
////		cout << u << " ";
////		for (int i = srcx; i <= 21; i++)
////		{
////			for (int j = srcy; j < 19; j++)
////			{
////				//for (i = AdjList[u].begin(); i != AdjList[u].end(); i++) {*/
////				int node = *i;//what is the node 
////				if (visited[node] == false && adjlist[i][u] != -1)
////				{
////					visited[node] = true;
////					q.push(node);
////				}
			//}
		//}

ghost::ghost()
{
	posIs[0] = 7; posJs[0] = 9;
	posIs[1] = 9; posJs[1] = 10;
	posIs[2] = 9; posJs[2] = 9;
	posIs[3] = 9; posJs[3] = 8;

	for (int i = 0; i < 4; i++)
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
//void ghost::Graph(const int& p_Vertices) : Vertices(p_Vertices) {//do we need this ??
//	AdjList = new vector<int>[u][v];
//}

//void Graph::AddEdge(int u, int v) //here he is drawing the adj list which is equivientto 
//{
//	AdjList[u].push_back(v);
//}