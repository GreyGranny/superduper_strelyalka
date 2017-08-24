#include "Player.h"
#include "Global.h"
#include "Game.h"
#include "Character.h"


Player::Player(void)
{
	mouseCoord = Point();
	mouseDown = false;
	upPress = downPress = rightPress = leftPress = false;
	character = new Character();
}


Player::~Player(void)
{
}

Point Player::getMouseCoordinates()
{
	return mouseCoord;
}

void Player::setMouseCoordinates(float x, float y)
{
	Point camera = Game::current()->getCamera();
	mouseCoord.x = camera.x + x;
	mouseCoord.y = Game::current()->getHeightWindow() - y + camera.y;
}

bool Player::getMouseDown()
{
	return mouseDown;
}

void Player::setMouseDown(bool is_down)
{
	mouseDown = is_down;
}

bool Player::isUpPress()
{
	return upPress;
}
bool Player::isDownPress()
{
	return downPress;
}
bool Player::isRightPress()
{
	return rightPress;
}
bool Player::isLeftPress()
{
	return leftPress;
}
void Player::setUpPress(bool is_press)
{
	upPress = is_press;
}
void Player::setDownPress(bool is_press)
{
	downPress = is_press;
}
void Player::setRightPress(bool is_press)
{
	rightPress = is_press;
}
void Player::setLeftPress(bool is_press)
{
	leftPress = is_press;
}

void Player::update()
{
	Point mouse_coord = getMouseCoordinates();
	character->rotation(mouse_coord);
	if (isUpPress())
		character->moveVertical(1);
	if (isDownPress())
		character->moveVertical(-1);
	if (isRightPress())
		character->moveHorizontal(1);
	if (isLeftPress())
		character->moveHorizontal(-1);

	if (mouseDown)
		character->weapon->shoot(character->getPosition(), character->getAngle());

	character->weapon->update();
}