#include"Animation.h"
#include"Character.h"
#include"Pacman.h"
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include <iostream>
#include <fstream>
using namespace sf;
class ghost: public Character
{
private:
    Sprite blinky, inky, clyde, forth;
    Sprite ghosts[4] = { blinky, inky, clyde, forth };
    Texture blinkyT, inkyT, clydeT, forthT;
public:
    ghost() {};
    void setposI(int x) { posI=x; }
    void setposy(int y) { posJ = y; }
    int getposx() { posI; }
    int getposy() { posJ; }
    //bool intersects(Pacman pac, ghost ghostt, int numberofghost)
    //{
    //    if (pac.getPacmanSprite().getGlobalBounds() == ghostt.getGlobalBound())
    //        return true;
    //    else
    //        return false;
    //}
    int setghosts()
    {//i and j for he array 
        for (int i = 0; i < 4;i++)
        {
            int county = 10;
            int countx = 20;
           // ghosts[i].setRadius(50);
            ghosts[i].setPosition(10, 20);
            county = county + 50;
            county = countx + 50;
        }
        blinkyT.loadFromFile("data/blinky.jpeg");
        inkyT.loadFromFile("data/inky.jpeg");
        clydeT.loadFromFile("data/clyde.jpeg");
        forthT.loadFromFile("data/pinky.jpeg");
        
    }
	/*int collide(Pacman pac, ghost ghostsArr[], int numbofghost) 
    {
        {
        if (intersects(pac.getPacmanSprite().getGlobalBounds(), ghosts[numbofghost].getGlobalBounds))
        {
           if (pac.superModeOn())
           {
                return 1;
           }
           else
           {
               return 2;
           }
       }
    //}*/
    //void eat(Pacman p){
    //    if (collide(p, ghost ghosts[]) == 2)
    //    {
    //        setghost();
    //        p.setPosition(400, 300);
    //        p.live--
    //            p.updatelive();//i dont know if this is correct}
    //    else()
    //        ghost[i]//if the pac man ate a ghost the gost should retirn home// i dont knw should amy or i do it
    //    }
        //void moverand()
        //{
        //    if (ghost.getlocalboundry() != = wall.getlocalboundry())
        //    {
        //        int m = rand() % 4 + 1;
        //        // 1 = up y+1 2=down y-1 3=right x+1 ghost.setposJ()++
        //        //4=left y-1 ghost.setposI()++ ghost.move();
        //        if (m == 1)// up
        //        {
        //            ghost.move(0, -100);
        //            posJ++;
        //        }
        //        if (m == 2)//down
        //        {
        //            ghost.move(0, 100);
        //            posJ--;
        //        }
        //        if (m == 3) //right
        //        {
        //            ghost.move(100, 0);
        //            posI++;
        //        }
        //        if (m == 4) //left
        //        {
        //            ghost.move(-100, 0);
        //            posI--;
        //        }
        //        else//check each side while mving in every direction 
        //        {
        //            if ((ghost.getposI() + 1) == -1 || (ghost.getposI() - 1) == -1))//moving to the right or left  ;wall to the rightor left he will go up or down
        //{
        //m = (rand() % 2) + 1;
        //if (m == 1)//up
        //{
        //    ghost.move(0, -100);
        //    posy--;
        //}
        //else//down
        //{
        //    ghost.move(0, 100);
        //    posJ++
        //}
        //}
                    /*  else if((ghost.getposx() -1) == -1)//moving to the left
                            {
                                m = (rand() % 2) + 1;
                                if (m == 1)
                                {
                                    ghost.move();
                                set();
                                }
                                else
                                {
                                    ghost.move();
                                    set();
                                }
                            }*/
                    //else if ((ghost.getposJ() - 1) == -1 || (ghost.getposJ() + 1) == -1)//moving to the up
                    //{
                    //    m = (rand() % 2) + 3;
                    //    if (m == 3)
                    //    {
                    //        ghost.move(100, 0);
                    //        posJ++;
                    //    }
                    //    else
                    //    {
                    //        ghost.move(-100, 0);
                    //        posI--;
                    //    }
                    //}
                    /* else  ((ghost.getposy() + 1) == -1)//moving to the down will move left or right is facing wall
                    {
                        m = (rand() % 2) + 3;
                        if (m == 3)
                        {
                            ghost.move();
                            ghost.set();
                        }
                        else
                        {
                            ghost.move();
                            ghost.set();
                        }
                    }
                    */

        //        }
        //    }


};
      /*{ if (((ghost.getpos
            ())+1)== -1)
            {x=x
            }
            if(arr[ghost.getposX][ghost.getposY+1])==-1)//arr()
            {arr[ghost.move(rand(),)}
        }*/
        /* struct direction
        {
            int up;
            int down;
            int left;
            int right;
        }:


            return 0;*/
        //};
        //int main()
        //{
        //    Pacman pac;
        //    ghost ghostt;
        //    ghost arrghost[4];
        //    const int rows = 10;
        //    const int columns = 10;
        //    int array[rows][columns];
        //    Sprite maze[rows][columns];

        //    // Create the main window
        //    RenderWindow game(Videomode(800, 600), "Pacman");

        //    //declare all of my variables that I need. Do any initializations here.



        //    // Start the game loop -- this is where my logic happens
        //    while (game.isOpen())
        //    {//if my user pressed a button on their keyboard
        //        //i want to set the position of ghosts but idkh
        //        if (event.type == Event::KeyPressed)
        //        {
        //            //what is the button they pressed?

        //            if (Keyboard::Escape: == true)
        //            {
        //                window.close();
        //            }
        //            else
        //            {for(int i=0;i<4;i++){
        //                arrghost[i].moverand();
        //                blinky.randmove();
        //                ///then after 3 seconds the blue then pink then yellow
        //            }
        //                   
        //            }
        //        }
        //        //clearscream
        //        game.clear;
        //        //draw
        //        game.draw(ghost.setghost());
        //        //update
        //        game.display;
        //    }
        //    return 0;
        //}
       
        //           