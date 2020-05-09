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
};