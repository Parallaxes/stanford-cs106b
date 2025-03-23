/*
 * Course: CS106B
 * Section: 1
 * Problem: 5 - Random Shuffling
 * File: CppFundamentals.cpp
 * Author: Parallaxes
 */

#include <iostream>
#include <algorithm>
#include "random.h"
#include <string>
#include "testing/SimpleTest.h"
using namespace std;

/*
 * Function: randomShuffle
 * ------------------------
 * One simple algorithm for shuffling a deck of cards is based on the following idea:
 *      * Choose a random card from the deck and remove it.
 *      * Shuffle the rest of the deck.
 *      * Place the randomly-chosen card on top of the deck.
 *      * Assuming that we choose the card that we put on top uniformly at random
 *        from the deck, this ends up producing a random shuffle of the deck.
 *
 * Write a function that accepts as input a string, then returns a random
 * permutation of the elements of the string using the above algorithm.
 * Your algorithm should be recursive and not use any loops (for, while, etc.).
 *
 */
string randomShuffle(string input) {
    /* Base case: there is only one permutation with a set of 0 */
    if (input.empty()) {
        return input;
    } else {
        /* Grab a random index */
        int i = randomInteger(0, input.size() - 1);
        /*
         * Recursive approach where we take the indexed char i input, then repeat the same
         * random shuffle on the rest of the string
         */
        return input[i] + randomShuffle(input.substr(0, i) + input.substr(i + 1));
    }
}

/* * * * * Provided Tests Below This Point * * * * */

// Since this algorithm is based on randomness, we cannot expect an exact output,
// but we can verify the validity of the solution.

PROVIDED_TEST("Provided Test: Verify that solution is at least valid permutation.") {
    string res = randomShuffle("23456789JQKA");
    sort(res.begin(), res.end());
    EXPECT_EQUAL(res, "23456789AJKQ");
}
