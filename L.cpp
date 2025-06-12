#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;

int n, m;
vector<vector<int>> adj;
int totalPaths = 0;

void dfs(int curr, int dest) {
    if (curr == dest) {
        totalPaths = (totalPaths + 1) % MOD;
        return;
    }

    for (int next : adj[curr]) {
        dfs(next, dest);
    }
}

int main() {
    cin >> n >> m;
    adj.resize(n + 1);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    dfs(1, n);
    cout << totalPaths << endl;

    return 0;
}
