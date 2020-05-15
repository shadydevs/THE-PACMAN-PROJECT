#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "Maze.h"
#include "Pacman.h"
using namespace sf;
using namespace std;

int main()
{
    RenderWindow window(VideoMode(712.5, 950), "PACMAN", Style::Close);
    window.setFramerateLimit(8);

	Pacman pac;
    //Texture pacT;
    //pacT.loadFromFile("data/pacman.png");
    //Animation animation(&pacT, Vector2u(3, 4), 0.3f);
   
    int row = 0;
    float deltaTime = 0.0f;
    Clock clock;

    //pac.pacman.setTextureRect(animation.uvRect);
	
    ghost ghostobj;
    ghostobj.setghosts();
    
    //Player player;
    ofstream playersInfo;

    //cout << "enter player name: ";
    //cin >> player.name;

    Maze maze("data/maze2.txt", "data/tile.png", "data/pellet.png");
    
    //int graph[V][V];

    //dijkstra(graph, 0);
    ghostobj.matrix();
    int randIteration = rand();
    int ghostTurn;
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
						pac.pacman.setTexture(&pac.tL);
                        pac.direction = Vector2i(-1, 0);
                    }
                    break;
                case Keyboard::Right:
                    if (maze.bitmap[pac.getposI()][pac.getposJ() + 1] != -1)
                    {
                        row = 1;
						pac.pacman.setTexture(&pac.tR);
                        pac.direction = Vector2i(1, 0);
                    }
                    break;
                case Keyboard::Up:
                    if (maze.bitmap[pac.getposI() - 1][pac.getposJ()] != -1)
                    {
                        row = 2;
						pac.pacman.setTexture(&pac.tU);
                        pac.direction = Vector2i(0, -1);
                    }
                    break;
                case Keyboard::Down:
                    if (maze.bitmap[pac.getposI() + 1][pac.getposJ()] != -1)
                    {
                        row = 3;
						pac.pacman.setTexture(&pac.tD);
                        pac.direction = Vector2i(0, 1);
                    }
                    break;
                case Keyboard::Enter:
                    cout << pac.getposI() << " " << pac.getposJ() << endl;
                default:
                    break;
                }
            }
        }
        pac.movePacman(maze.bitmap);
        //do_bfs(&ghostobj, pac.getposI(), pac.getposJ());      //triggers infinite loop

        for (int i = 0; i < 4; i++)
        {
            if (pac.getScore() >= ghostobj.getOutScore[i])
                ghostTurn = i;
        }

        //ghosts random movement
        for (int i = 0; i <= ghostTurn; i++)
        {
            srand(randIteration);
            randIteration += rand();
            int nextDir = rand() % 4;
            if (nextDir == 0)
                ghostobj.direction[i] = Vector2i(-1, 0);
            else if (nextDir == 1)
                ghostobj.direction[i] = Vector2i(1, 0);
            else if (nextDir == 2)
                ghostobj.direction[i] = Vector2i(0, 1);
            else if (nextDir == 3)
                ghostobj.direction[i] = Vector2i(0, -1);
        }

        ghostobj.moveGhost(maze.bitmap);
        pac.eatPellet(maze.bitmap, maze.mazeSprites);

        for (int i = 0; i < 4; i++)
        {
            if (ghostobj.posIs[i] == pac.getposI() && ghostobj.posJs[i] == pac.getposJ()) {
                pac.eat(ghostobj, i);
                cout << pac.getScore() << endl;
            }
        }


        //ghostobj.getOut(pac.getScore());
        //cout << pac.getScore() << endl;

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
        for (int i = 0; i < sizey; i++)
        {
            for (int j = 0; j < sizex; j++)
            {
                window.draw(maze.mazeSprites[i][j]);
            }
        }
        for (int i = 0; i < 4; i++)
        {
            window.draw(ghostobj.ghosts[i]);
        }
        window.draw(pac.pacman);
        window.display();
    }

    return 0;
}