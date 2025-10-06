string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";

    // Sort the array
    sort(strs.begin(), strs.end());

    string first = strs[0];
    string last = strs.back();
    int i = 0;

    // Compare characters of first and last string
    while (i < first.size() && i < last.size() && first[i] == last[i]) {
        i++;
    }

    return first.substr(0, i);
}

int main() {
    vector<string> words1 = {"flower", "flow", "flight"};
    cout << "Longest Common Prefix: " << longestCommonPrefix(words1) << endl; // Output: "fl"

    vector<string> words2 = {"dog", "racecar", "car"};
    cout << "Longest Common Prefix: " << longestCommonPrefix(words2) << endl; // Output: ""

    return 0;
}
