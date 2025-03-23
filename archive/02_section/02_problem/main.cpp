/**
 * Course        : CS106B
 * Section       : 2
 * Problem       : 2 - Queues
 * File          : main.cpp
 * Author        : Parallaxes
 * 
 * This program reverses a given queue using an external stack structure
 */

#include <queue>
#include <stack>

using namespace std;

/// @brief reverses a queue in-place
/// @param q the queue to verse
void reverseQueue(queue<int>& q) {
    stack<int> s;
    while (!q.empty()) {
        s.push(q.front());
        s.pop();
    }

    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
}