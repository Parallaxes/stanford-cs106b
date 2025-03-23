/**
 * Course     : CS106B
 * Programming: 1
 * Problem    : 3 - Graphics
 * File       : main.cpp
 * Author     : Parallaxes
 * 
 * This program uses the SFML graphics library to draw the Sierpinski Triangle.
 * User clicks three vertexes within the graphics window, which we'll refer to
 * as A, B, and C. We then execute this procedure:
 * 1. Randomly choose one vertex as the current point
 * 2. Draw a small filled circle around the current point
 * 3. Randomly choose one vertex and move the current point half the distance
 *    toward that vertex
 * 4. Repeat steps 2 & 3 (stop when the user clicks the mouse)
 * 
 * I ignored the mouse click to stop because I'm lazy :) Also, I was supposed 
 * to use Stanford's C++ libraries but I wanted some experience with the SFML 
 * library. The code I wrote here is quite bad "best practice" wise, but I'm 
 * sure later programs will *hopefully* improve. I'm not a big fan of the 
 * global vars I used to count the number of vertices/points; it'd be much
 * better practice to just integrate them into the structs as statics, but 
 * whatever.
 */

#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <chrono>
#include <thread>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

using namespace std;

// Initialize global time variable for mouse click tracking
chrono::time_point<chrono::steady_clock> lastClickTime;

// Constants for screen dimensions
const int SCREEN_WIDTH = sf::VideoMode::getDesktopMode().width;
const int SCREEN_HEIGHT = sf::VideoMode::getDesktopMode().height;

// Global vars keeping track of # of vertices and points
// Naturally, it would be much better it embed them in the structs, but oh well
int vertex_cnt = 0;
int point_cnt = 0;

/// @struct Vertex
/// @brief Represents a vertex with a position and a graphical circle shape.
/// 
/// The Vertex struct contains the x and y coordinates of a vertex, a graphical
/// representation of the vertex using an sf::CircleShape, and an equality operator
/// to compare two vertices.
/// 
///  @var Vertex::xPos
/// The x-coordinate of the vertex.
/// 
/// @var Vertex::yPos
/// The y-coordinate of the vertex.
/// 
/// @var Vertex::circle
/// The graphical representation of the vertex as a circle.
/// 
/// @fn Vertex::operator==(const Vertex& other) const
/// @brief Compares two vertices for equality.
/// @param other The other vertex to compare with.
/// @return True if both vertices have the same x and y coordinates, false otherwise.
///
struct Vertex {
    double xPos;
    double yPos;
    sf::CircleShape circle;
    bool operator==(const Vertex& other) const {
        return xPos == other.xPos && yPos == other.yPos;
    }
};

// Intialize vectors for vertices (starting three points) and points (to be 
// drawn)
vector<Vertex> vertices;
vector<Vertex> points;

/// @brief Regulates mouse clicks. Placed vertices on screen where the user 
///        clicks; unintended overlapping points prevented by delay
/// @param window the graphics window to draw points on
void driver(sf::RenderWindow& window) {
    // Intialize vars for tracking time
    auto now = chrono::steady_clock::now();
    // The duration is the the time between last mouse click and now
    auto duration = chrono::duration_cast<chrono::milliseconds>(now - lastClickTime).count();

    // Place a point if LMB is pressed and there have been 500 ms since the 
    // last click
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && duration > 500) {
        // Generate the vertex with type Vertex
        Vertex vertex;
        vertex.circle.setRadius(SCREEN_WIDTH * 0.001);

        // Get the location of the mouse
        sf::Vector2f mousePos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));

        // Get location relative to screen and radius
        vertex.xPos = mousePos.x - vertex.circle.getRadius();
        vertex.yPos = mousePos.y - vertex.circle.getRadius();

        // Construct the point
        vertex.circle.setPosition(vertex.xPos, vertex.yPos);
        vertices.push_back(vertex);

        // Increment count and reset time
        vertex_cnt++;
        lastClickTime = now;
    }
}

/// @brief The main draw loop to form the Sierpinski Triangle
/// @param vertices a mutable reference to the vertices vector to iterate over
/// @param points a mutable reference to the points vector to add new points
///               to be drawn
void loop(vector<Vertex>& vertices, vector<Vertex>& points) {
    //Generate the point with type Vertex
    Vertex point;
    point.circle.setRadius(SCREEN_WIDTH * 0.0005);

    // Get a random vertex from the 3 vertices, denoted v1
    Vertex v1 = vertices[rand() % 3];

    Vertex v2;
    // If first vertex, use another random vertex
    if (point_cnt == 0) {
        v2 = vertices[rand() % 3];
        // If using same vertex by change, generate a new one
        while (v2 == v1) {
            v2 = vertices[rand() % 3];
        }
    } else {
        // Get the last point pushed to the points vector and use as random
        // point
        v2 = points[point_cnt - 1];
    }
    
    // Find the midpoint between the two random vertices and draw a point
    point.xPos = (v1.xPos + v2.xPos) / 2;
    point.yPos = (v1.yPos + v2.yPos) / 2;
    point.circle.setPosition(point.xPos, point.yPos);

    // Push the constructed point and increment the point count
    points.push_back(point);
    point_cnt++;
}

int main() {
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH * 0.25, SCREEN_HEIGHT * 0.5), "SFML Window");

    // Seed the RNG
    srand(time(NULL));

    while (window.isOpen()) {
        // On close event, exit program
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Only allow user to draw points if there are not 3 vertices yet
        if (vertex_cnt < 3) {
            driver(window);
        } else {
            // Else, start the draw loop
            loop(vertices, points);
        }

        // Refresh the window every pass (probably extraneous)
        window.clear();

        // Loop over vertices and points.
        // This, of course, will take massive tolls on performance with larger
        // numbers. I'll find some way to optimize this manana
        for (const auto& vertex : vertices) {
            window.draw(vertex.circle);
        }
        for (const auto& point : points) {
            window.draw(point.circle);
        }
        window.display();
    }

    return 0;
}