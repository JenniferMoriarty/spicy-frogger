#include<SFML/Graphics.hpp>
#include<iostream>
#include"factory.h"
#include"globals.h"
#include"frog.h"
using namespace std;

//LOOK HERE! Set up an enum for game state names and a variable to keep track of which one you're on
enum GAMESTATES { BEGIN, MAP, FIGHT, MENU, END };
enum GAMESTATES current_state = BEGIN;

int main()
{
	srand(time(NULL));
	int timer = 0;
	bool keys[] = { false, false, false, false, false };

	CarFactory CarGen;//uses factory to make game objects

	frog player;

	//SFML boilerplate
	sf::RenderWindow screen(sf::VideoMode(1000, 1000), "Frogger!");

	vector<gameObject*> stuff; //make a vector of POINTERS (lets us do the next couple lines)
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 2; j++) {
			stuff.push_back(CarGen.create(i * 400 + 100, j * 200 + 500, LEFT));
			stuff.push_back(CarGen.create(i * 300 + 200, j * 200 + 600, RIGHT));
		}

	while (screen.isOpen() && player.returnLives() > 0) {//game loop##################################################################
		sf::Event event;

		while (screen.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				screen.close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				keys[LEFT] = true;
			}
			else keys[LEFT] = false;

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
				keys[SPACE] = true;
			}
			else keys[SPACE] = false;

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				keys[RIGHT] = true;
			}
			else keys[RIGHT] = false;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				keys[UP] = true;
			}
			else keys[UP] = false;

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				keys[DOWN] = true;
			}
			else keys[DOWN] = false;
		}
	
		//LOOK HERE! have a switch statement that handles different inputs depending on what state you're in!
		switch (current_state) {
		case BEGIN:
			cout << "opening screen. press space to start." << endl;
			if (keys[SPACE] == true)
				current_state = MAP;
			break;
		case MAP:
			timer++;
			if (timer > 200) {
				player.jump(keys);
				timer = 0;
			}
			for (vector<gameObject*>::iterator i = stuff.begin(); i != stuff.end(); i++)//walk through the vector
			{
				(*i)->move();
				if ((*i)->collide(player.returnX(), player.returnY()) == true) {
					player.ded();
					current_state = FIGHT;
				}
			}
			break;
		}

		//render section---------------------------------------------------------------
		screen.clear();

		//LOOK HERE! Have another switch statement that displays different things based on what state you're in!
		switch (current_state) {
		case BEGIN:
			screen.clear(sf::Color(0, 200, 0, 255));
			cout << "opening screen" << endl;
			break;

		case MAP:
			for (vector<gameObject*>::iterator i = stuff.begin(); i != stuff.end(); i++)//walk through the vector
			{
				(*i)->draw(screen); //THIS IS WHY WE MADE A VIRTUAL FUNCTION IN THE PARENT CLASS!

				//(*i)->printInfo(); //for testing purposes
			}
			player.draw(screen);
			break;

		case FIGHT:
			screen.clear(sf::Color(0, 200, 200, 255));
			cout << "opening screen" << endl;
			break;
		}
		screen.display();

	}
	cout << "game over." << endl;
	return 0;
}

