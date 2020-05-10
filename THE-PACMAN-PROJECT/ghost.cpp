#include"Animation.h"
#include"Character.h"
#include"Pacman.h"
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include <iostream>
#include <fstream>
using namespace sf;
class ghost : public Character
{
private:
	Sprite blinky, inky, clyde, forth;

	Texture blinkyT, inkyT, clydeT, forthT;
public:
	Sprite ghosts[4] = { blinky, inky, clyde, forth };
	ghost() {};
	void setposI(int x) { posI = x; }
	void setposy(int y) { posJ = y; }
	//  int getposx() { posI; }
	 // int getposy() { posJ; }
	  //bool intersects(Pacman pac, ghost ghostt, int numberofghost)
	  //{
	  //    if (pac.getPacmanSprite().getGlobalBounds() == ghostt.getGlobalBound())
	  //        return true;
	  //    else
	  //        return false;
	  //}
	void setghosts()
	{
		//i and j for he array 

		blinkyT.loadFromFile("data/blinky.jpeg");
		inkyT.loadFromFile("data/inky.jpeg");
		clydeT.loadFromFile("data/clyde.jpeg");
		forthT.loadFromFile("data/pinky.jpeg");
		ghosts[0].setTexture(blinkyT);
		ghosts[1].setTexture(inkyT);
		ghosts[2].setTexture(clydeT);
		ghosts[3].setTexture(forthT);


		ghosts[0].setPosition(9 * 37.5 + (18.75f - 7.5f), 8 * 37.5 + (18.75f - 7.5) + (37.5f * 2.0f));
		ghosts[1].setPosition(10 * 37.5 + (18.75f - 7.5f), 9 * 37.5 + (18.75f - 7.5) + (37.5f * 2.0f));
		ghosts[2].setPosition(9 * 37.5 + (18.75f - 7.5f), 9 * 37.5 + (18.75f - 7.5) + (37.5f * 2.0f));
		ghosts[3].setPosition(8 * 37.5 + (18.75f - 7.5f), 9 * 37.5 + (18.75f - 7.5) + (37.5f * 2.0f));

	}
	//void moverand(ghost ghost, int bitmap[21][19])
	////        {
	//          while(  bitmap[posI][posJ - 1]==-1|| bitmap[posI-1][posJ])
	//            while (ghost.getGlobalBounds() != wall.getGlobalBounds())
	//            {
	//                int m = rand() % 4 + 1;
	//                // 1 = up y+1 2=down y-1 3=right x+1 ghost.setposJ()++
	//                //4=left y-1 ghost.setposI()++ ghost.move();
	//                if (m == 1)// up
	//                {
	//                    ghost[0].move(0, -10);
	//                    posJ++;
	//                }
	//                if (m == 2)//down
	//                {
	//                    ghosts[1].move(0, 10);
	//                    posJ--;
	//                }
	//                if (m == 3) //right
	//                {
	//                    ghosts[0].move(100, 0);
	//                    posI++;
	//                }
	//                if (m == 4) //left
	//                {
	//                    ghosts[0].move(-100, 0);
	//                    posI--;
	//                }
	//                else//check each side while mving in every direction 
	//                {
	//                    if (ghosts[0].getposI() + 1 < -1 || (ghosts[0].getposJ() - 1) == -1)
	//                        //moving to the right or left  ;wall to the rightor left he will go up or down
	//                    {
	//                        m = (rand() % 2) + 1;
	//                        if (m == 1)//up
	//                        {
	//                            ghosts[0].move(0, -100);
	//                            posJ--;
	//
	//                        }
	//                        else//down
	//                        {
	//                            ghosts[0].move(0, 100);
	//                            posJ++;
	//                        }
	//                    }
	//                    /*  else if((ghost.getposx() -1) == -1)//moving to the left
	//                            {
	//                                m = (rand() % 2) + 1;
	//                                if (m == 1)
	//                                {
	//                                    ghost.move();
	//                                set();
	//                                }
	//                                else
	//                                {
	//                                    ghost.move();
	//                                    set();
	//                                }
	//                            }*/
	//                    else if ((ghosts[0].getposJ() - 1) == -1 || (ghosts[0].getposJ() + 1) == -1)//moving to the up
	//                    {
	//                        m = (rand() % 2) + 3;
	//                        if (m == 3)
	//                        {
	//                            ghosts[0].move(100, 0);
	//                            posJ++;
	//                        }
	//                        else
	//                        {
	//                            ghosts[0].move(-100, 0);
	//                            posI--;
	//                        }
	//                    }
	//                    /* else  ((ghost.getposy() + 1) == -1)//moving to the down will move left or right is facing wall
	//                    {
	//                        m = (rand() % 2) + 3;
	//                        if (m == 3)
	//                        {
	//                            ghost.move();
	//                            ghost.set();
	//                        }
	//                        else
	//                        {
	//                            ghost.move();
	//                            ghost.set();
	//                        }
	//                    }
	//                    */
	//
	//                    //        }
	//                    //    }
	//
	//
	//                };
	//                /*{ if (((ghost.getpos
	//                      ())+1)== -1)
	//                      {x=x
	//                      }
	//                      if(arr[ghost.getposX][ghost.getposY+1])==-1)//arr()
	//                      {arr[ghost.move(rand(),)}
	//                  }*/
};