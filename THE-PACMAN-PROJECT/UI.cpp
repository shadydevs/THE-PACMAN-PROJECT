#include "UI.h"

UI::UI()
{
	arial.loadFromFile("data/arial.ttf");
	for (int i = 0; i < UInum; i++)
	{
		element[i].setFont(arial);
		element[i].setFillColor(sf::Color::Yellow);
	}

	element[0].setPosition(0, 0);
}
