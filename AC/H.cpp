#include <bits/stdc++.h>

using namespace std;

int find(const string& s) {
    unordered_map<char, int> freq;

    for (char c : s) {
        freq[c]++;
    }

    for (int i = 0; i < s.length(); i++) {
        if (freq[s[i]] == 1) {
            return i;
        }
    }

    return -1;
}

int main() {
    string input;
    cin >> input;

    int result = find(input);
    cout << result << endl;

    return 0;
}
