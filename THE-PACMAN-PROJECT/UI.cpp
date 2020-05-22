#include "UI.h"

UI::UI(Pacman pac)
{
	pacLives = new CircleShape[pac.getLives()];
	livesT.loadFromFile("data/pacman-left.png");

	arial.loadFromFile("data/arial.ttf");
	for (int i = 0; i < UInum; i++)
	{
		element[i].setFont(arial);
		element[i].setFillColor(Color::Yellow);
	}

	// [0] -> score
	element[0].setPosition(0, 0);
	element[0].setString("SCORE: " + to_string(pac.getScore()));

	// [1] -> lives
	element[1].setPosition(0.0f, 23 * 38.0f);
	element[1].setString("REMAINING LIVES: ");
	
	for (int i = 0; i < pac.getLives(); i++)
	{
		pacLives[i].setTexture(&livesT);
		pacLives[i].setRadius(pac.pacman.getSize().x / 2.0f);
		pacLives[i].setPosition((i + 7.5) * 37.5f, 23 * 38.2f);
	}

	// [2] -> super timer
	element[2].setPosition(13.5f * 37.5f, 1.3 * 37.5f);
	element[2].scale(0.7f, 0.7f);

}

void UI::display(sf::RenderWindow& window, Pacman pac, float pelletTimer)		// function to update variables and render them
{
	for (int i = 0; i < UInum; i++)
	{
		if (i == 2 && pac.superModeOn)
		{
			element[i].setString("power left: " + to_string(int(pelletTimer)));
			window.draw(element[i]);
		}
		window.draw(element[i]);
	}

	for (int i = 0; i < pac.getLives(); i++)
	{
		window.draw(pacLives[i]);
	}
}
