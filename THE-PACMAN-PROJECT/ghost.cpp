#include "ghost.h"

ghost::ghost() 
{
	posIs[0] = 7; posJs[0] = 9;
	posIs[1] = 9; posJs[1] = 10;
	posIs[2] = 9; posJs[2] = 9;
	posIs[3] = 9; posJs[3] = 8;

	direction[0] = Vector2i(-1, 0);
	for (int i = 1; i < 4; i++)
	{
		direction[i] = Vector2i(0, 0);
		startPosition[i] = Vector2f(posJs[i] * 37.5 + (18.75f - 7.5f), posIs[i] * 37.5 + (18.75f - 7.5) + (37.5f * 2.0f));
	}

	getOutScore[0] = 0;			//blinky gets out immediately
	getOutScore[1] = 50;		//pinky gets out right after blinky so low get out score required
	getOutScore[2] = 500;
	getOutScore[3] = 750;
}

void ghost::setghosts()
{
	//i and j for he array 

	blinkyT.loadFromFile("data/blinky.jpeg");
	inkyT.loadFromFile("data/inky.jpeg");
	clydeT.loadFromFile("data/clyde.jpeg");
	pinkyT.loadFromFile("data/pinky.jpeg");
	ghosts[0].setTexture(blinkyT);
	ghosts[1].setTexture(pinkyT);
	ghosts[2].setTexture(inkyT);
	ghosts[3].setTexture(clydeT);

	for (int i = 0; i < 4; i++)
	{
		ghosts[i].setPosition(posJs[i] * 37.5 + (18.75f - 7.5f), posIs[i] * 37.5 + (18.75f - 7.5) + (37.5f * 2.0f));
	}
}

void ghost::moveGhost(int bitmap[21][19]) {
	for (int i = 0; i < 4; i++)
	{
		if (bitmap[posIs[i] + direction[i].y][posJs[i] + direction[i].x] != -1)
		{
			ghosts[i].move(37.5 * direction[i].x, 37.5 * direction[i].y);
			posIs[i] = posIs[i] + direction[i].y;
			posJs[i] = posJs[i] + direction[i].x;
		}
	}
}










	//void setposI(int x) { posI = x; }
	//void setposy(int y) { posJ = y; }



	//  int getposx() { posI; }
	 // int getposy() { posJ; }
	  //bool intersects(Pacman pac, ghost ghostt, int numberofghost)
	  //{
	  //    if (pac.getPacmanSprite().getGlobalBounds() == ghostt.getGlobalBound())
	  //        return true;
	  //    else
	  //        return false;
	  //}









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