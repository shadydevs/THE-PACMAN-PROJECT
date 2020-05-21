#include <SFML/Graphics.hpp>
#define UInum 5		//the maximum amount of texts we will display
class UI
{
private:
	sf::Font arial;
	sf::Text element[UInum];		//the ui text elements

public:
	UI();
	void display(sf::RenderWindow& window, bool isPelletTimer, int pelletTimer, int score);
};

