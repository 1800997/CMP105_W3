#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects

	circle.setRadius(15);
	circle.setPosition(300, 300);
	circle.setFillColor(sf::Color::Red);
	circle.setOutlineColor(sf::Color::Magenta);
	circle.setOutlineThickness(5.f);

	circleSpeed = 150.f;

	rect.setSize(sf::Vector2f(40, 40));
	rect.setFillColor(sf::Color::Green);
	rect.setPosition(0, 0);

	rectSpeed = 1000.f;

	bouncyCircle.setRadius(20);
	bouncyCircle.setPosition(200,200);
	bouncyCircle.setFillColor(sf::Color::Yellow);

	bouncySpeed = 500.f;
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Left) && (rect.getPosition().x > 0))
	{
		rect.move(-(rectSpeed * dt), 0);
	}

	if (input->isKeyDown(sf::Keyboard::Right) && (rect.getPosition().x+40 < sizeX))
	{
		rect.move(rectSpeed * dt, 0);
	}
	
	if (input->isKeyDown(sf::Keyboard::Up) && (rect.getPosition().y > 0))
	{
		rect.move(0, -(rectSpeed * dt));
	}

	if (input->isKeyDown(sf::Keyboard::Down) && (rect.getPosition().y+40 < sizeY))
	{
		rect.move(0, rectSpeed * dt);
	}


	if (input->isKeyDown(sf::Keyboard::Add))
	{
		bouncySpeed++;
	}
	
	if (input->isKeyDown(sf::Keyboard::Subtract))
	{
		bouncySpeed--;
	}
	
}

// Update game objects
void Level::update(float dt)
{
	sizeX = window->getSize().x;
	sizeY = window->getSize().y;
	int circleXPosition = circle.getPosition().x;



	if (circleXPosition+30 == sizeX)
	{
		backwards = true;
	}
	else if (circleXPosition == 0)
	{
		backwards = false;
	}
	

	if (backwards)
	{
		circle.move(-(circleSpeed * dt), 0);
	}
	else
	{
		circle.move(circleSpeed * dt, 0);
	}

	int ballPosX = bouncyCircle.getPosition().x;
	int ballPosY = bouncyCircle.getPosition().y;

	if (ballPosX+40 >= sizeX || ballPosX <= 0)
	{
		dX = -dX;
	}
	else if (ballPosY <= 0 || ballPosY+40 >= sizeY)
	{
		dY = -dY;
	}
	
	bouncyCircle.move(bouncySpeed * dt * dX, bouncySpeed * dt * dY);
}

// Render level
void Level::render()
{
	beginDraw();
	
	window->draw(circle);
	window->draw(rect);
	window->draw(bouncyCircle);

	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}