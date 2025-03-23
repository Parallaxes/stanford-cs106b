/**
 * Course        : CS106B
 * Section       : 2
 * Problem       : 1 - Vectors (AKA C++ ArrayLists...)
 * File          : main.cpp
 * Author        : Parallaxes
 * 
 * This program (predominantly disfunctional) answers a few questions under 
 * Section 2
 */

#include <string>
#include <vector>

using namespace std;

// Provided in Section Handout #2
struct eMailMsg {
    string to; // i.e. "professor@stanford.edu"
    string from; // i.e. "student@stanford.edu"
    string message; // body of message
    string subject; // i.e. "CS106 Rocks!"
    int date; // date email was sent
    int time; // time email was sent
};

// Part A
vector<eMailMsg> mail;


// Part B

/// @brief removes mail with "SPAM" in the subject
/// @param mail the vector of mail messages
void removeSpam(vector<eMailMsg>& mail) {
    for (int i = 0; i < mail.size(); i++) {
        eMailMsg msg = mail[i];
        if (msg.subject.find("SPAM")) {
            mail.erase(mail.begin() + i);
        }
    }
}


// Part C
struct eMailMsg {
    vector<string> to; // allow arbitrary number of email addresses
    string from;
    string message;
    string subject;
    int date;
    int time;
};

eMailMsg email;
string lastAddress = email.to[email.to.size() - 1];