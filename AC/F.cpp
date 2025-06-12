#include <bits/stdc++.h>
using namespace std;

int calPoints(vector<string>& operations) {
    stack<int> st;
    for (string op : operations) {
        if (op == "+") {
            int top1 = st.top(); st.pop();
            int top2 = st.top();
            st.push(top1);
            st.push(top1 + top2);
        } else if (op == "D") {
            st.push(st.top() * 2);
        } else if (op == "C") {
            st.pop();
        } else {
            st.push(stoi(op));
        }
    }

    int total = 0;
    while (!st.empty()) {
        total += st.top();
        st.pop();
    }
    return total;
}

int main() {
    string str;
    getline(cin, str);

    stringstream ss(str);
    string token;
    vector<string> operations;

    while (ss >> token) {
        operations.push_back(token);
    }

    cout << calPoints(operations) << endl;
    return 0;
}
