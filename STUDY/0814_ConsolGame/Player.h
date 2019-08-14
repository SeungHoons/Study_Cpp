#pragma once


enum STATE
{
	TITLE,
	INTRO,
	INGAME,
	ENDING,
	MAP_MAKE
};


class Player
{
private:

	STATE sceneState;

public:
	Player();
	~Player();

	void setScene(STATE scene);
	STATE getScene();
};

