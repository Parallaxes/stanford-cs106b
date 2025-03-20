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

vector<string> parse(string file, vector<string> scores) {
    fstream in;
    in.open(file.c_str());
    if (in.fail()) {
        throw runtime_error("Couldn't find file! ");
    }

    string score;
    while (in >> score) {
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
}