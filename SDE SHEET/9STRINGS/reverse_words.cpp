#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s) {
    stringstream ss(s);
    string word;
    vector<string> words;

    // Extract words from stringstream
    while (ss >> word) {
        words.push_back(word);
    }

    // Build reversed string
    string result;
    for (int i = words.size() - 1; i >= 0; i--) {
        result += words[i];
        if (i > 0) result += " "; // add space between words
    }
    return result;
}

int main() {
    string s = "Hello world this is C++";
    cout << reverseWords(s) << endl; // Output: "C++ is this world Hello"
}

//we can also use stringstream + stack too