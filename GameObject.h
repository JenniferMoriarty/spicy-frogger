#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include"globals.h"

using namespace std;

class gameObject {
public:
    //these VIRTUAL functions are placeholders in the parent class
    //they will be defined by the various child classes
    //by using virtual functions, we can create a vector of "gameObjects" in main, 
    //and be able to put ALL the stuff into one tidy vector!
    virtual void draw(sf::RenderWindow& window) = 0; 
    virtual void move() = 0;
    virtual void printInfo() = 0;
    virtual bool collide(int x, int y) = 0;
protected:
    float xpos;
    float ypos;
    int green = rand() % 100;
    int blue = rand() % 200;
    int direction = RIGHT;

};

class car : public gameObject {
public:
    car(int x, int y, int d) { //constructor
        
        xpos = x;
        ypos = y;
        direction = d;
    }
    void draw(sf::RenderWindow& window);
    void move();
    bool collide(int x, int y);
    void printInfo() { cout << "I am a car and my position is " << xpos << "," << ypos << endl; }

};

 
