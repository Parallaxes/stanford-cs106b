/**
 * Course     : CS106B
 * Programming: 1
 * Problem    : 1 - Variables, arithmetic, and control structures
 * File       : main.cpp
 * Author     : Parallaxes
 * 
 * This program calculates perfect numbers found within the range of
 * 1 to 10,000, inclusive.
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


const int BOUND = 10000;

/// @brief This function calculates if a number is perfect. A number `n` is
///        considered perfect if it is equal to the sum of its divisors less
///        than itself.
/// @param n integer describing the number to be tested
/// @return A bool describing whether the number is "perfect" or not.
bool isPerfect(int n) {
    int sum = 0;
    // Iterate through divisors less than n itself and add to sum
    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }

    // Number is perfect because sum of divisors = n
    return n == sum;
}

int main() {
    // Test for perfect numbers from 1 to 10,000, inclusive.
    for (int i = 1; i <= BOUND; i++) {
        if (isPerfect(i)) {
            cout << i << endl;
        }
    }

    return 0;
}