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
    RenderWindow window(VideoMode(712.5, 950), "PACMAN", Style::Close);
    window.setFramerateLimit(10);

	Pacman pac;
    //Texture pacT;
    //pacT.loadFromFile("data/pacman.png");
    //Animation animation(&pacT, Vector2u(3, 4), 0.3f);
   
    int row = 0;
    float deltaTime = 0.0f;
    Clock clock;
	/*Texture pacR;
	pacR.loadFromFile("data/pacman-right");
	Texture pacU;
	pacU.loadFromFile("data/pacman-up");
	Texture pacD;
	pacD.loadFromFile("data/pacman-down");*/

    //pac.pacman.setTextureRect(animation.uvRect);
	
    ghost ghostobj;
    ghostobj.setghosts();
    
    //Player player;
    ofstream playersInfo;

    //cout << "enter player name: ";
    //cin >> player.name;

    Maze maze("data/maze2.txt", "data/tile.png", "data/pellet.png", pac);

    //pac.setPosition();


    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();

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
                    if (maze.bitmap[pac.getposI()][pac.getposJ() - 1] != -1)
                    {
                        row = 0;
						/*pac.pacman.setTexture(&pac.getT());*/
                        pac.direction = Vector2i(-1, 0);
                    }
                    break;
                case Keyboard::Right:
                    if (maze.bitmap[pac.getposI()][pac.getposJ() + 1] != -1)
                    {
                        row = 1;

						/*pac.pacman.setTexture(&pacR);*/
                        pac.direction = Vector2i(1, 0);
                    }
                    break;
                case Keyboard::Up:
                    if (maze.bitmap[pac.getposI() - 1][pac.getposJ()] != -1)
                    {
                        row = 2;
						/*pac.pacman.setTexture(&pacU);*/
                        pac.direction = Vector2i(0, -1);
                    }
                    break;
                case Keyboard::Down:
                    if (maze.bitmap[pac.getposI() + 1][pac.getposJ()] != -1)
                    {
                        row = 3;
						/*pac.pacman.setTexture(&pacD);*/
                        pac.direction = Vector2i(0, 1);
                    }
                    break;
                default:
                    break;
                }
            }
        }
        pac.movePacman(maze.bitmap);

        pac.eatPellet(maze.bitmap, maze.mazeSprites);
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
        //pac.pacman.setTextureRect(animation.uvRect);

        window.clear();
        for (int i = 0; i < 4; i++)
        {
            window.draw(ghostobj.ghosts[i]);
        }
        for (int i = 0; i < sizey; i++)
        {
            for (int j = 0; j < sizex; j++)
            {
                window.draw(maze.mazeSprites[i][j]);
            }
        }
        window.draw(pac.pacman);
        window.display();
    }

    return 0;
}