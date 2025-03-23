/**
 * Course        : CS106B
 * Section       : 2
 * Problem       : 4 - Map Warm-up
 * File          : main.cpp
 * Author        : Parallaxes
 * 
 * This program finds the most frequent character in a given file.
 */

#include <iostream>
#include <string>
#include <map>
#include <fstream>

using namespace std;

/// @brief Find the most frequent char in a given file
/// @param in the file in which to find the most frequent char
/// @param numOccurences a reference parameter for the number of occurences 
/// the most frequent char occurs
/// @return the most frequently occuring char in the file
char mostFrequentCharacter(ifstream &in, int &numOccurences) {
    map<char, int> mp;
    char ch;
    while (in.get(ch)) {
        mp[ch]++;
    }

    // Initiate a default value
    char mostFreq = '\0';
    for (const auto &elem : mp) {
        // Picking up whitespace with char code -38, so ignore that
        if (elem.second > numOccurences && elem.first - '0' != -38) {
            mostFreq = elem.first;
            numOccurences = elem.second;
        }
    }

    return mostFreq;
}

int main() {
    string file = "chars.txt";
    ifstream in;
    in.open(file.c_str());
    if (in.fail()) {
        cout << "Failed to open the file!" << endl;
        return -1; // Terminate on error
    }

    int numOccurences = 0;
    cout << "Most frequent char: " << mostFrequentCharacter(in, numOccurences)
         << endl;

    return 0;
}