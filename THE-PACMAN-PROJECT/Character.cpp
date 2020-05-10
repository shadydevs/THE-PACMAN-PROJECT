#include "Character.h"

Character::Character()
{
	direction = Vector2i(0, 0);
}
int Character::getposI()
{
	return posI;
}
void Character::setposI(int i)
{
	posI = i;
}
int Character::getposJ()
{
	return posJ;
}
void Character::setposJ(int j)
{
	posJ = j;
}