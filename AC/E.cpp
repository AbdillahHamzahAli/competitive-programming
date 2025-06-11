#include <bits/stdc++.h>
using namespace std;

int main(){
    deque<int> q;
    int n; cin >> n;
    while(n--){
        string cmd;cin >> cmd;
        if(cmd == "tambahDepan"){
            int x; cin >> x;
            q.push_front(x);
        } else if(cmd == "tambahBelakang"){
            int x; cin >> x;
            q.push_back(x);
        } else if(cmd == "depan"){
            if(q.empty()) {
                cout << "\n"; continue;
            }
            cout << q.front() << endl;
            q.pop_front();
        } else  if(cmd == "belakang"){
            if(q.empty()) {
                cout << "\n"; continue;
            }
            cout << q.back() << endl;
            q.pop_back();
        } else if(cmd == "balik"){
            reverse(q.begin(), q.end());
        }
    }
}

//   