/**
 * Course     : CS106B
 * Programming: 1
 * Problem    : 2 - Simulation and use of random/io libraries
 * File       : main.cpp
 * Author     : Parallaxes
 * 
 * This program simulates a number of trials of elections with a predicted
 * error rate. Certain voters may be incorrectly recorded, and thus inverted.
 * Here, we calculate the probability of an invalidated election due to this 
 * error.
 */

#include <iostream>
#include <string>
#include <random>

using namespace std;

// The number of elections to simulate
const int NUM_TRIALS = 500;

/// @brief Simulates a number of elections given paramters
/// @param num_voters the number of voters in the election
/// @param percent_diff the percent difference between candidates
/// @param percent_err the rate of error of the ballot system
/// @return The chance the election will be invalidated given the paramters
///         over `NUM_TRIALS` elections.
double simulation(int num_voters, double percent_diff, double percent_err) {
    // Calculate the initial numbers of voters for each candidate 
    // before simulation
    int prelim_cand1 = int(num_voters * (50 + percent_diff) / 100);
    int prelim_cand2 = int(num_voters * (50 - percent_diff) / 100);

    int final_cand1 = 0, final_cand2 = 0, invalid = 0;
    // Seed the RNG
    srand(time(0));

    // Iterate over NUM_TRIALS elections
    for (int i = 0; i < NUM_TRIALS; i++) {
        // For each voter for cand1...
        for (int j = 0; j < prelim_cand1; j++) {
            // percent_err chance that the voter is inverted
            if (rand() % 100 + 1 <= percent_err * 100) {
                final_cand2++;
            } else {
                final_cand1++;
            }
        }
        // Ditto
        for (int j = 0; j < prelim_cand2; j++) {
            if (rand() % 100 + 1 <= percent_err * 100) {
                final_cand1++;
            } else {
                final_cand2++;
            }
        }

        // Increment the invalid count if the election was influenced by error
        if ((prelim_cand1 > prelim_cand2 && final_cand1 < final_cand2) ||
            (prelim_cand1 < prelim_cand2 && final_cand1 > final_cand2)) {
            invalid++;
        }
    }

    return double(invalid) / NUM_TRIALS * 100;
}

// Struct for storing params because I didn't want to use tuples
struct Params {
    int num_voters;
    double percent_diff;
    double percent_err;
};

/// @brief Driver function. Accepts inputs and validates the inputs.
/// @return The struct params, with params supplied from input
Params driver() {
    Params params;
    int num_voters;
    double percent_diff, percent_err;
    bool valid_num = false, valid_diff = false, valid_err = false;

    while (!valid_num) {
        cout << "Enter number of voters: ";
        cin >> num_voters;

        if (num_voters < 0) {
            cout << "Invalid number of voters! Please enter a non-negative number." << endl;
        } else {
            valid_num = true;
            params.num_voters = num_voters;
        }
    }

    while (!valid_diff) {
        cout << "Enter percentage spread between candidates: ";
        cin >> percent_diff;

        if (percent_diff < 0 || percent_diff > 1.0) {
            cout << "Invalid percentage! Percentages must be between 0 to 1.0." << endl;
        } else {
            valid_diff = true;
            params.percent_diff = percent_diff;
        }
    }

    while (!valid_err) {
        cout << "Enter voting error percentage: ";
        cin >> percent_err;

        if (percent_err < 0 || percent_err > 1.0) {
            cout << "Invalid percentage! Percentages must be between 0 to 1.0." << endl;
        } else {
            valid_err = true;
            params.percent_err = percent_err;
        }
    }
    
    return params;
}

int main() {
    Params params = driver();
    cout << "Chance of an invalid election result after " << NUM_TRIALS << " trials = " 
         << simulation(params.num_voters, 
                       params.percent_diff, params.percent_err)
         << "%" << endl;
}