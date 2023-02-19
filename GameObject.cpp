#include"GameObject.h"
#include"globals.h"
#include<SFML/Graphics.hpp>
#include<iostream>
using namespace std;

//draw the "car"
void car::draw(sf::RenderWindow& window) { 
    sf::RectangleShape vehicle(sf::Vector2f(100,50));
    vehicle.setFillColor(sf::Color(250, green, blue));
    vehicle.setPosition(xpos, ypos);
    window.draw(vehicle);
}

//movement function: can move left or right
//resets position to other side when moves offscreen
void car::move() {
    if (direction == LEFT) {
    if (xpos < -100)
        xpos = 1100;
    xpos -= .1;
}
    else if (direction == RIGHT) {
        if (xpos > 1100)
            xpos = -100;
        xpos += .1;
    }
}

//bounding box collision with frog
bool car::collide(int x, int y) {
    if (x+20>xpos && x < xpos+100 && y<ypos+20 && y+20>ypos) {
        cout << "DED!" << endl;
        return true;
    }
    else
        return false;

}

