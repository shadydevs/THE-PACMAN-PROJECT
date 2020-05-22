#include "Pacman.h"
#define UInum 5		//the maximum amount of texts that we will display
class UI
{
private:
	Font arial;
	Text element[UInum];		//the ui text elements
	CircleShape* pacLives;		//dynamic array so that it suits any level with different number of lives
	Texture livesT;

public:
	UI(Pacman pac);
	void display(sf::RenderWindow& window, Pacman pac, float pelletTimer);
};

