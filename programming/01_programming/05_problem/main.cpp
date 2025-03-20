/**
 * Course     : CS106B
 * Programming: 1
 * Problem    : 4 - Strings
 * File       : main.cpp
 * Author     : Parallaxes
 * 
 * This program calculates the Soundex code for a given surname. The Soundex 
 * algorithm follows as such:
 * 1. Keep the first letter of the surname (convert to uppercase if necessary)
 * 2. Convert all other letters in the surname to a digit using the Soundex 
 *    data table (discard any non-letter characters: dashes, spaces, and so on)
 * 3. Remove any consecutive duplicate digits (e.g. A122235 becomes A1235)
 * 4. Remove any zeros
 * 5. Make resulting code exactly length 4 by truncating or padding with zeros
 */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

vector<int> parse(string file) {
    fstream in;
    in.open(file.c_str());
    if (in.fail()) {
        throw runtime_error("Couldn't find file!");
    }

    int score;
    vector<int> scores;
    while (in >> score) {
        scores.push_back(score);
    }

    return scores;
}

void histogram(vector<int> scores) {
    for (int i = 0; i < 10; i++) {
        
    }
}


int main() {
    string file;
    cout << "Enter the name of the scoring file: ";
    cin >> file;

    histogram(parse(file));
}