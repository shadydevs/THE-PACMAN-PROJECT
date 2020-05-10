#include <SFML/Graphics.hpp>
#include <queue>
using namespace sf;
class ghost
{
private:
	Sprite blinky, pinky, inky, clyde;
	Texture blinkyT, pinkyT, inkyT, clydeT;

	int getOutScore[4];			//the score pac reaches when each ghost gets out of home
public:

	void BFS();

	Sprite ghosts[4] = { blinky, pinky, inky, clyde };
	Vector2i direction[4];
	Vector2f startPosition[4];
	int posIs[4];
	int posJs[4];
	ghost();
	void setghosts();
	void moveGhost(int bitmap[21][19]);
};