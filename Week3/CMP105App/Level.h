#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include <string.h>
#include <iostream>


class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt);
	void update(float dt);
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;

	sf::CircleShape circle;
	float circleSpeed;
	int sizeX;
	int sizeY;
	bool backwards = false;

	sf::RectangleShape rect;
	float rectSpeed;

	sf::CircleShape bouncyCircle;
	float bouncySpeed;
	int dX = 1;
	int dY = 1;
	bool bounce = false;
};