/**
 * Course     : CS106B
 * Programming: 1
 * Problem    : 3 - Graphics
 * File       : main.cpp
 * Author     : Parallaxes
 * 
 * This program simulates a number of trials of elections with a predicted
 * error rate. Certain voters may be incorrectly recorded, and thus inverted.
 * Here, we calculate the probability of an invalidated election due to this 
 * error.
 */

#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace std;

const int SCREEN_WIDTH = sf::VideoMode::getDesktopMode().width;
const int SCREEN_HEIGHT = sf::VideoMode::getDesktopMode().height;

struct Point {
    double xPos;
    double yPos;
    sf::CircleShape circle;
};

vector<Point> points;

void driver(sf::RenderWindow& window) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        Point point;
        point.circle.setRadius(SCREEN_WIDTH * 0.001);
        sf::Vector2f mousePos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
        point.xPos = mousePos.x - point.circle.getRadius();
        point.yPos = mousePos.y - point.circle.getRadius();
        point.circle.setPosition(point.xPos, point.yPos);
        points.push_back(point);
    }
}

int main() {
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH * 0.25, SCREEN_HEIGHT * 0.5), "SFML Window");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (points.size() <= 3 * 4) {
            driver(window);
        }

        window.clear();
        for (const auto& point : points) {
            window.draw(point.circle);
        }
        window.display();
    }

    return 0;
}