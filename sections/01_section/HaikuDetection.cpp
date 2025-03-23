/*
 * Course: CS106B
 * Section: 1
 * Problem: 7 - Haiku Detection
 * File: HaikuDetection.cpp
 * Author: Parallaxes
 *
 * This program determines whether three lines of inputted text form a valid haiku.
 */

#include <string>
#include "simpio.h"
#include "tokenscanner.h"
#include "testing/SimpleTest.h"
using namespace std;


bool isVowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}

int countSyllables(const string& word) {
    int cnt = 0;
    bool prevVowel = false;

    for (int i = 0; i < word.length(); i++) {
        if (isVowel(word[i])) {
            if (!prevVowel) {
                cnt++; // Start of new vowel group
                prevVowel = true;
            }
        } else {
            prevVowel = false;
        }
    }

    /* Special case: if the word ends in 'e' and there is more than one syllable, ignore it */
    if (word.length() > 2 && word.back() == 'e' && !isVowel(word[word.length() - 2]) && cnt > 1) {
        cnt--;
    }

    return cnt > 0 ? cnt : 1; // Ensure at least one syllable
}

int syllablesInLine(string line) {
    TokenScanner scanner(line);
    scanner.ignoreWhitespace();

    int syllables = 0;
    while(scanner.hasMoreTokens()) {
        string token = scanner.nextToken();
        syllables += countSyllables(token);
    }

    return syllables;
}

bool isHaiku(string line1, string line2, string line3) {
    return syllablesInLine(line1) == 5 &&
           syllablesInLine(line2) == 7 &&
           syllablesInLine(line3) == 5;
}

// int main() {
//     string line1 = getLine("1st line: ");
//     string line2 = getLine("2nd line: ");
//     string line3 = getLine("3rd line: ");

//     if (isHaiku(line1, line2, line3)) {
//         cout << "The text you entered is a haiku." << endl;
//     } else {
//         cout << "The text you entered is NOT a haiku" << endl;
//     }

//     return 0;
// }

STUDENT_TEST("Is haiku") {
    string line1 = "Faint drums of thunder";
    string line2 = "Company to clouded skies";
    string line3 = "I wonder if rain";
    EXPECT(isHaiku(line1, line2, line3)); // True
}

STUDENT_TEST("Is not a haiku") {
    string line1 = "Faint drums of thunder";
    string line2 = "Company to clouded skies";
    string line3 = "I wonder if rain will come";
    EXPECT(!isHaiku(line1, line2, line3)); // False
}
