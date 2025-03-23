/*
 * Course: CS106B
 * Section: 1
 * Problems:
 *  1 - Returning and Printing
 *  2 - Recursion Tracing
 *  3 - Testing and Debugging
 * File: CppFundamentals.cpp
 * Author: Parallaxes
 */

#include <iostream>
#include <string.h>
#include "testing/SimpleTest.h"

using namespace std;


/* 1 - Returning and Printing */

/*
 * void, because no value is returned (sent to console instead)
 * "Havana ooh nana" is printed to the console when called
 */
void printLyrics_v1() {
    cout << "Havana ooh na na" << endl;
}

/*
 * string, because a string is returned
 * "Havana ooh nana" is returned as a string
 */
string printLyrics_v2() {
    return "Havana ooh na na";
}

/*
 * string, because a string is returned
 * "H" is returned as a string
 */
string printLyrics_v3() {
    return "H";
}

/*
 * char, because a singular char is returned
 * 'H' is returned as a char
 */
char printLyrics_v4() {
    return 'H';
}

/*
 * It is not really appropriate for all the functions to be named printLyrics because only one
 * function actually *prints* something (printLyrics_v1()), but the other functions simply return
 * a value when called.
 */


/*************************************************************************************************/


/* 2 - Recursion Tracing */

string reverseOf(string s) {
    if (s == "") {
        return "";
    } else {
        return reverseOf(s.substr(1)) + s[0];
    }
}

/* See solution diagram */


/*************************************************************************************************/


/* 3 - Testing and Debugging */

/*
 * Fix 1: Use chars instead of strings for singular chars. The current and previous vars are
 * actually extraneous anyways, and we can just compare the chars at the indexes directly.
 *
 * Fix 2: On the first iteration of the loop, when i = 0, we try to access an out of bounds value
 * (0 - 1 = -1) which would cause an error.
 *
 * Fix 3: The return statement inside the loop means that the function only checks the first pair
 * of chars. That is, the function exits as soon as the return statement is reached, so the next
 * iteration doesn't occurr.
 *
 * Fix 4: If the string doesn't contain doubled chars, a value is never returned.
 */
bool hasDoubledCharacter(const string& text) {
    for (int i = 1; i < text.size(); i++) {
        if (text[i] == text[i - 1]) {
            return true;
        }
    }
    return false;
}

PROVIDED_TEST("Detects doubled characters") {
    EXPECT(hasDoubledCharacter("aa"));
    EXPECT(hasDoubledCharacter("bb"));
}

STUDENT_TEST("Strings without doubled chars") {
    EXPECT(!hasDoubledCharacter("abcd")); // Nothing doubled
    EXPECT(!hasDoubledCharacter("aba")); // Not consecutively doubled
    EXPECT(!hasDoubledCharacter("Aa")); // Not same char
}

STUDENT_TEST("Strings with doubled chars not at front") {
    EXPECT(hasDoubledCharacter("abb")); // Back
    EXPECT(hasDoubledCharacter("abccde")); // Middle
}

STUDENT_TEST("Strings with doubled non-alphabetical chars") {
    EXPECT(hasDoubledCharacter("**")); // Symbols
    EXPECT(hasDoubledCharacter("  ")); // Spaces
    EXPECT(hasDoubledCharacter("00")); // Numbers
}

STUDENT_TEST("Short strings") {
    EXPECT(!hasDoubledCharacter("a")); // Too short
    EXPECT(!hasDoubledCharacter("")); // Too short
}
