/*
 * Course: CS106B
 * Section: 1
 * Problem: 4 - Human Pyramids
 * File: HumanPyramids.cpp
 * Author: Parallaxes
 */

#include "doctest.h"
using namespace std;

/*
 * Function: peopleInPyramidOfHeight
 * ---------------------------------
 * Takes as input the height of the human pyramid and 
 * returns the number of people in that pyramid. A 
 * human pyramid is a triangular stack of a bunch of
 * people where each person (except the one at the top)
 * supports their weight on the two people below them.
 */
int peopleInPyramidOfHeight(int n) {
    if (n == 0) {
        return 0;
    } else {
        return n + peopleInPyramidOfHeight(n - 1);
    }
}

/* * * * * Provided Tests Below This Point * * * * */

TEST_CASE("peopleInPyamidOfHeight tests") {
    CHECK(peopleInPyramidOfHeight(0) == 0);
    CHECK(peopleInPyramidOfHeight(1) == 1);
    CHECK(peopleInPyramidOfHeight(2) == 3);
    CHECK(peopleInPyramidOfHeight(3) == 6);
}
