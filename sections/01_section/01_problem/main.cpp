#include <iostream>
#include <string>

using namespace std;


string CensorString1(string text, string remove) {
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

void CensorString2(string& text, string remove) {
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
    cout << "Test 1: " << CensorString1(text1, remove1) << endl;

    // Test modifying original string
    string text2 = "Stanford University";
    string remove2 = "nt";
    CensorString2(text2, remove2);
    cout << "Test 2: " << text2 << endl;

    return 0;
}