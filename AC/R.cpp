#include <bits/stdc++.h>
using namespace std;

int currSize;
vector<pair<int, int>> currCor;
vector<pair<int, int>> largeCol;
int large = 0;
int total = 0;
int even = 0;

void dfs(vector<vector<char>>& grid, int i, int j) {
    int m = grid.size();
    int n = grid[0].size();
    if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] != '+')
        return;
    grid[i][j] = '#';
    currSize++;
    currCor.push_back({i, j});

    dfs(grid, i + 1, j);
    dfs(grid, i - 1, j);
    dfs(grid, i, j + 1);
    dfs(grid, i, j - 1);
}

void solve(vector<vector<char>>& grid, int m, int n) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == '+') {
                currSize = 0;
                currCor.clear();
                dfs(grid, i, j);
                total++;
                if (currSize % 2 == 0) {
                    even++;
                }
                if (currSize > large) {
                    large = currSize;
                    largeCol = currCor;
                }
            }
        }
    }
}

int main() {
    vector<vector<char>> matrix;
    int m, n; cin >> m >> n;
    for(int i = 0; i < m; i++){
        vector<char> row;
        for(int j = 0; j < n; j++){
            char c; cin >> c;
            row.push_back(c);
        }
        matrix.push_back(row);
    }

    solve(matrix,m,n);

    cout << total << " " << large << " " << even << endl;

    return 0;
}
