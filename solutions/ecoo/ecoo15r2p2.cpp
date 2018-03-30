/*
 Solution to ECOO '15 R2 P2 - So So by Ava Pun
 Key concepts: brute force, simulation, implementation
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;

int R, C;
vector<string> arr;
bool done[35][35];

bool check(vector<string> &grid, int i, int j) {
    int cnt = 0;
    int prev = 'X';
    
    for (int k = -2; k <= 2; k++) {
        if (j + k < 0 || j + k >= C) {
            continue;
        }
        if (grid[i][j + k] == 'R') {
            cnt = 0;
            prev = grid[i][j + k];
        } else if (grid[i][j + k] == prev) {
            cnt++;
        } else {
            cnt = 1;
            prev = grid[i][j + k];
        }
        if (cnt >= 3) {
            return true;
        }
    }
    
    cnt = 0;
    prev = 'X';
    for (int k = -2; k <= 2; k++) {
        if (i + k < 0 || i + k >= R) {
            continue;
        }
        if (grid[i + k][j] == 'R') {
            cnt = 0;
            prev = grid[i + k][j];
        } else if (grid[i + k][j] == prev) {
            cnt++;
        } else {
            cnt = 1;
            prev = grid[i + k][j];
        }
        if (cnt >= 3) {
            return true;
        }
    }
    
    return false;
}

bool solve(vector<string> grid) {

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            done[i][j] = false;
        }
    }
    int cnt = 0;
    char prev = 'X';
    for (int i = 0; i < R; i++) {
        cnt = 0;
        for (int j = 0; j < C; j++) {
            if (grid[i][j] == prev) {
                cnt++;
            } else {
                cnt = 1;
                prev = grid[i][j];
            }
            if (cnt >= 3) {
                for (int k = 0; k < 3; k++) {
                    done[i][j - k] = true;
                }
            }
        }
    }

    cnt = 0;
    prev = 'X';
    for (int j = 0; j < C; j++) {
        cnt = 0;
        for (int i = 0; i < R; i++) {
            if (grid[i][j] == prev) {
                cnt++;
            } else {
                cnt = 1;
                prev = grid[i][j];
            }
            if (cnt >= 3) {
                for (int k = 0; k < 3; k++) {
                    done[i - k][j] = true;
                }
            }
        }
    }

    cnt = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (done[i][j]) {
                grid[i][j] = 'R';
                cnt++;
            }
        }
    }
    if (cnt == R * C) {
        return true;
    }
    
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C - 1; j++) {
            if (grid[i][j] != 'R' && grid[i][j + 1] != 'R' && grid[i][j] != grid[i][j + 1]) {
                swap(grid[i][j], grid[i][j + 1]);
                if (check(grid, i, j) || check(grid, i, j + 1)) {
                    if (solve(grid)) {
                        return true;
                    }
                }
                swap(grid[i][j], grid[i][j + 1]);
            }
        }
    }
    for (int j = 0; j < C; j++) {
        for (int i = 0; i < R - 1; i++) {
            if (grid[i][j] != 'R' && grid[i + 1][j] != 'R' && grid[i][j] != grid[i + 1][j]) {
                swap(grid[i][j], grid[i + 1][j]);
                if (check(grid, i, j) || check(grid, i + 1, j)) {
                    if (solve(grid)) {
                        return true;
                    }
                }
                swap(grid[i][j], grid[i + 1][j]);
            }
        }
    }
    
    return false;
    
}

int main() {
    
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    for (int test = 1; test <= 10; test++) {
        
        cin >> R >> C;
        arr.resize(R);

        for (int t = 1; t <= 5; t++) {
            for (int i = 0; i < R; i++) {
                cin >> arr[i];
            }
            if (solve(arr)) {
                cout << 'S';
            } else {
                cout << 'N';
            }
        }
        cout << "\n";
        
    }
    
    return 0;
}
