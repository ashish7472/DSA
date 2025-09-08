//String Matching Algo with O(n+m)

#include <iostream>
#include <string>
using namespace std;

void rabinKarp(string txt, string pat) {
    int d = 256;  // number of characters in the input alphabet
    int q = 101;  // a prime number to avoid large hash values
    int M = pat.size();
    int N = txt.size();
    int p = 0;    // hash value for pattern
    int t = 0;    // hash value for current window in text
    int h = 1;

    // The value of h is "pow(d, M-1) % q"
    for (int i = 0; i < M - 1; i++)
        h = (h * d) % q;

    // Calculate initial hash values for pattern and first window
    for (int i = 0; i < M; i++) {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    // Slide the pattern over text one by one
    for (int i = 0; i <= N - M; i++) {
        // If the hash values match, check characters one by one
        if (p == t) {
            bool match = true;
            for (int j = 0; j < M; j++) {
                if (txt[i + j] != pat[j]) {
                    match = false;
                    break;
                }
            }
            if (match)
                cout << "Pattern found at index " << i << endl;
        }

        // Calculate hash for next window: Remove leading char, add trailing char
        if (i < N - M) {
            t = (d * (t - txt[i] * h) + txt[i + M]) % q;
            // Make sure hash is positive
            if (t < 0)
                t = (t + q);
        }
    }
}

int main() {
    string txt = "abedabcabcabc";
    string pat = "abc";
    rabinKarp(txt, pat);
    return 0;
}