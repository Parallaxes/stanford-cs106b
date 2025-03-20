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
#include <unordered_map>

using namespace std;

// Soundex data table
const unordered_map<char, int> VALUES =
{
    {'a', 0},
    {'e', 0},
    {'i', 0},
    {'o', 0},
    {'u', 0},
    {'h', 0},
    {'w', 0},
    {'y', 0},
    {'b', 1},
    {'f', 1},
    {'p', 1},
    {'v', 1},
    {'c', 2},
    {'g', 2},
    {'j', 2},
    {'k', 2},
    {'q', 2},
    {'s', 2},
    {'x', 2},
    {'z', 2},
    {'d', 3},
    {'t', 3},
    {'m', 4},
    {'n', 4},
    {'l', 5},
    {'r', 6},
};

/// @brief Calculates the Soundex code for a given surname
/// @param name the name to be converted to a Soundex code
/// @return The Soundex code for the surname
string soundex(string name) {
    // Grab first char in name as uppcase
    string res = string(1, toupper(name[0]));

    // Grab only alphabetical chars from the name and append to res
    for (int i = 1; i < name.size(); i++) {
        if (isalpha(name[i])) {
            // Get the associated Soundex value and append
            res += to_string(VALUES.at(name[i]));
        }
    }

    // Remove consecutive digits in res
    for (int i = 0; i < res.size() - 1; i++) {
        if (res[i] == res[i + 1] || res[i] == '0') {
            res.erase(i, 1);
            i--;
        }
    }

    // Truncate or pad with zeros for exactl length of 4
    if (res.size() > 4) {
        res = res.substr(0, 4);
    } else {
        while (res.size() < 4) {
            res += '0';
        }
    }

    return res;
}

int main() {
    string name;
    // Prompt user until RETURN
    while (true) {
        cout << "Enter surname (RETURN to quit): ";
        getline(cin, name);
        if (name.empty()) break;
        cout << "Soundex code for " + name + " is " + soundex(name) << endl;
    }
    
    return 0;
}
