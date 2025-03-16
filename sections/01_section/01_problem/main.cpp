/**
 * Course        : CS106B
 * Section       : 1
 * Problem       : 1 - Removing all occurrences of characters
 * File          : main.cpp
 * Author        : Parallaxes
 * Section Leader: N/A
 * 
 * This program removes specific instances of a string from another string
 * using both copy and in-place editing.
 */

#include <iostream>
#include <string>

using namespace std;

/// @brief Removes specific instances of a string from another string;
///        creates a copy of the string
/// @param text string to remove string from
/// @param remove string to remove from text
/// @return edited string
string censorString1(string text, string remove) {
    string result = "";
    
    for (int i = 0; i < text.length(); i++) {
        bool found = false;
        for (int j = 0; j < remove.length(); j++) {
            if (text[i] == remove[j]) {
                found = true;
                break;
            }
        }

        if (!found) {
            result += text[i];
        }
    }

    return result;
}

/// @brief Removes specific instances of a string from another string;
///        edits the string in-place.
/// @param text string to remove string from
/// @param remove string to remove from text
void censorString2(string& text, string remove) {
    for (int i = 0; i < remove.length(); i++) {
        int pos = 0;
        while ((pos = text.find(remove[i], pos)) != string::npos) {
            text.replace(pos, 1, "");
        }
    }
}

int main() {
    // Test completely new string
    string text1 = "Stanford University";
    string remove1 = "nt";
    cout << "Test 1: " << censorString1(text1, remove1) << endl;

    // Test modifying original string
    string text2 = "Stanford University";
    string remove2 = "nt";
    censorString2(text2, remove2);
    cout << "Test 2: " << text2 << endl;

    return 0;
}