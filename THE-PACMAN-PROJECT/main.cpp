#include <SFML/Graphics.hpp>
//#include <Clock.hpp>
#include <iostream>
#include <fstream>
#include "Maze.h"
#include "Pacman.h"
#include "Animation.h"
#include "Character.h"
#include "ghost.cpp"
using namespace sf;
using namespace std;


//int collide(Pacman pac, ghost ghostsArr[]) {
//    for (int i = 0; i < 4; i++)
//    {
//        if (intersects(pac.getGlobalBounds(), ghostsArr[i].getGlobalBounds)) {
//            if (pac.superModeOn()) {
//                return 1;
//            }
//            else
//            {
//                return 2;
//            }
//        }
//    }
//
//    return 0;
//}
//
//int collide(pacman pac, pellet pels[]) {
//    for (int i = 0; i < 4; i++)
//    {
//        if (intersects(pac.getGlobalBounds(), pels[i].getGlobalBounds))
//        {
//
//        }
//    }
//
//    return 0;
//}

int main()
{
	Pacman *pacmanPointer;
	pacmanPointer = new Pacman();
    RenderWindow window(VideoMode(712.5, 950), "PACMAN", Style::Close);
    window.setFramerateLimit(60);

    
    //Animation animation(&Tpac, Vector2u(3, 4), 0.3f);
    //int row = 0;
    //float deltaTime = 0.0f;
    //Clock clock;

    ghost ghostsArr[4];

    //Player player;
    ofstream playersInfo;

    //cout << "enter player name: ";
    //cin >> player.name;

    Maze maze("data/maze2.txt", "data/tile.png", "data/pellet.png", pacmanPointer);

    //pac.setPosition();


    while (window.isOpen())
    {
        //deltaTime = clock.restart().asSeconds();

        Event evnt;
        while (window.pollEvent(evnt))
        {
            if (evnt.type == Event::Closed)
                window.close();
			if (evnt.type == Event::KeyPressed)
			{
				switch (evnt.key.code)
			{
				case Keyboard::Escape:
					window.close();
					break;
				
				case Keyboard::Left:
					cout << "hi";
					maze.pac->movePacman('L', maze.bitmap);
					break;
				case Keyboard::Right:
					maze.pac->movePacman('R', maze.bitmap);
					break;
				case Keyboard::Up:
					maze.pac->movePacman('U', maze.bitmap);
					break;
				case Keyboard::Down:
					maze.pac->movePacman('D', maze.bitmap);
					break;
				default:
					break;
				}
			}

        }

        //if (collide(pac, ghostsArr) == 1) {
        //    pac.eat(ghost);
        //}
        //else if (collide(pac, ghostsArr) == 2) {
        //    ghost.eat(pac);
        //}

        //if (pac.isDead()) {
            /*
            end of game code {
                update score leaderboard
                cout gameover
                save to file
                ask if want to replay
            }
            */
        //}

        //animation.Update(row, deltaTime);
        //pac.setTextureRect(animation.uvRect);

        window.clear();
        for (int i = 0; i < sizey; i++)
        {
            for (int j = 0; j < sizex; j++)
            {
                window.draw(maze.mazeSprites[i][j]);
            }
        }

        window.display();
    }

    return 0;
}