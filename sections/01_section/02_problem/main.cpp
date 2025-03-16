/**
 * Course        : CS106B
 * Section       : 1
 * Problem       : 2 - Files and Structs
 * File          : main.cpp
 * Author        : Parallaxes
 * Section Leader: N/A
 * 
 * This program calculates statistics (min, max, and average) for a given list 
 * of scores from file input. Output is returned as a struct of the stats.
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/// @brief Struct containing score stats
struct Stats {
    int min;
    int max;
    int avg;
};

/// @brief Takes file input and reads scores line by line to calculate average,
///        min, and max of scores.
/// @param filename string name of the file to read scores from
/// @return struct of the min, max, and average of the scores
Stats calculateStats(string filename) {
    ifstream in;
    in.open(filename.c_str());
    // Throw error if we are unable to open the file
    if (in.fail()) {
        throw std::runtime_error("Couldn't read file " + '"' + filename + '"');
    }

    // Initialize struct and vars
    Stats stats;
    int score;
    int cnt = 0, total = 0;

    // Read until error
    while (true) {
        in >> score;
        // If there are no more lines, break
        if (in.fail()) {
            break;
        };

        total += score;
        cnt++;

        // Replace min or max if the current score is less/greater than the
        // previously lowest/highest score
        if (score < stats.min) {
            stats.min = score;
        }
        if (score > stats.max) {
            stats.max = score;
        }
    }

    // Calculate the average of the scores as as double
    stats.avg = double(total) / cnt;

    // Close file input stream
    in.close();

    // Return the struct of stats
    return stats;
}

int main() {
    // Test calculateStats function
    string filename = "scores.txt";
    Stats stats = calculateStats(filename);
    cout << "Min: " << stats.min << ", Max: " << stats.max << ", Avg: " << stats.avg << endl;
    
    return 0;
}