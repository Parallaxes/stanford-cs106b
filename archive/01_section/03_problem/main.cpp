/**
 * Course        : CS106B
 * Section       : 1
 * Problem       : 3 - Vectors
 * File          : main.cpp
 * Author        : Parallaxes
 * Section Leader: N/A
 * 
 * This program calculates the frequencies of alphabetical chars in a file.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


const int ALPHABET_SIZE = 26;

/// @brief Counts the frequencies of each letter in a file case insensitive.
///        outputs to STDOUT.
/// @param filename string name of the file to calculate letter freqs
void countLetters(string filename) {
    ifstream in;
    in.open(filename.c_str());
    // Throw error upon failure to read line
    if (in.fail()) {
        throw std::runtime_error("Couldn't read file " + '"' + filename + '"');
    }

    // Initialize a frequency count vector with 0s and size of alphabet
    vector<int> freqs(ALPHABET_SIZE, 0);

    string line;
    // Iterate over lines of input
    while (getline(in, line)) {
        // For each line...
        for (int i = 0; i < line.length(); i++) {
            // Convert the char to lowercase
            line[i] = tolower(line[i]);
            // Convert the lowercase char to alphabet index
            int index = line[i] - 'a';
            // Increment the frequency of that char
            freqs[index]++;
        }
    }

    // Output the frequency counts of each alphabetical char
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        char letter = 'a' + i;
        cout << letter << ": " << freqs[i] << endl;
    }
}

int main() {
    // Test function with letters.txt
    string filename = "letters.txt";
    countLetters(filename);

    return 0;
}