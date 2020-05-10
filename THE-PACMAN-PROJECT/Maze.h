#include "SFML/Graphics.hpp"
#include <fstream>
#include <string>
using namespace std;
using namespace sf;

const int sizex = 19, sizey = 21;
class Maze
{
private:
	ifstream bitmapFile;
	
	Texture pelletT;
	Texture tileT;
public:
	int bitmap[sizey][sizex];

	Maze(string, string, string);
	Sprite mazeSprites[sizey][sizex];
};

