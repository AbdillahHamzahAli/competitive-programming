#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;cin >> n;
    map<string, int> m;
    while(n--){
        string s;cin >> s;
        if(s == "ADD"){
            string a; int b; cin >> a >> b;
            m[a] == 0 ? m[a] = b : m[a] += b;
        } else if(s == "SELL"){
            string a; int b; cin >> a >> b;
            if(m.find(a) == m.end()){
                cout << "item not found" << endl;
            } else if(m[a] < b){
                cout << "not enough stock" << endl;
            } else if(m[a] >= b){
                m[a] -= b;
                cout << "SUCCESS" << endl;
            }
        }
    }
}