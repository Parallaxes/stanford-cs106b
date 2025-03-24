/*
 * Course: CS106B
 * Section: 1
 * Problem: 6- Computing Statistics
 * File: Statistics.cpp
 * Author: Parallaxes
 */

#include <iostream>
#include <fstream>
#include <string>
#include "doctest.h"
using namespace std;

struct Statistics {
    double min;     // Smallest value in the file
    double max;     // Largest value in the file
    double average; // Average value in the file
};

/*
 * Function: documentStatisticsFor
 * -------------------------------
 * Reads in a file of numbers via istream and calculates statistics on
 * it (i.e. min, max, average). Represents stats in form of struct 
 * defined above.
 */
Statistics documentStatisticsFor(istream& input) {
    /*
     * Initialize a Statistics object with min = 0 and max = 0. Generally, it's probably not a
     * good idea to initialize with default 0 values because the problem statement doesn't really
     * specifiy whether there are negative scores or not.
     */
    Statistics stats;
    stats.min = 0;
    stats.max = 0;

    /* Intialize var for input and keep track of values for average calculation */
    double val, total = 0;
    int numVals = 0;

    /* Read the file, updating min and max if applicable and incrementing sum and number of values */
    while (input >> val) {
        stats.min = min(stats.min, val);
        stats.max = max(stats.max, val);

        numVals++;
        total += val;
    }

    /* Compute the average */
    stats.average = total / numVals;

    return stats;
}

/* * * * * Provided Tests Below This Point * * * * */

TEST_CASE("Provided Test: Use sample text file to compute statistics.") {
    ifstream input;
    input.open("stats.txt");
    Statistics s = documentStatisticsFor(input);
    CHECK(s.min == -4.2);
    CHECK(s.max == 30.12);
    CHECK(s.average == 5.802);
}
