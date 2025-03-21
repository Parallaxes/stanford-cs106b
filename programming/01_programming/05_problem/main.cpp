/**
 * Course     : CS106B
 * Programming: 1
 * Problem    : 5 - File processing and vectors
 * File       : main.cpp
 * Author     : Parallaxes
 * 
 * This program sorts a list of scores into histogram buckets.
 */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;


/// @brief Parses file input and appends scores to buckets
/// @param file the file to read scores from
/// @param scores the template vector of scores
/// @return The vector of scores with read scores appended
vector<string> parse(string file, vector<string> scores) {
    fstream in;
    in.open(file.c_str());
    if (in.fail()) {
        throw runtime_error("Couldn't find file! ");
    }

    string score;
    while (in >> score) {
        // We can identify the bucket of a score in correspondance to its index
        // in the vector by its first digit
        scores[score[0] - '0'] += 'X';
    }

    return scores;
}

int main() {
    string file;
    vector<string> scores = {
        "0-9: ", "10-19: ", "20-29: ", "30-39: ", "40-49: ", 
        "50-59: ", "60-69: ", "70-79: ", "80-89: ", "90-99: "
    };

    bool success = false;
    while (!success) {
        cout << "Enter the name of the scoring file: ";
        cin >> file;

        // If parse returns a read error, reprompt user
        try {
            scores = parse(file, scores);
            success = true;
        } catch (const runtime_error& e) {
            cout << e.what() << "Please try again." << endl;
        }
    }
    
    for (const auto score : scores) {
        cout << score << endl;
    }

    return 0;
}