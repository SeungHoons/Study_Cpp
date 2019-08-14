#include "Player.h"



Player::Player()
{
}


Player::~Player()
{
}

void Player::setScene(STATE scene)
{
	sceneState = scene;
}

STATE Player::getScene()
{
	return sceneState;
}
