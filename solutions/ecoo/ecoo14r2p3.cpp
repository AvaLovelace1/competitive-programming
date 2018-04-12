/*
 Solution to ECOO '14 R2 P3 - EasySweeper by Ava Pun
 Key concepts: simulation
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
const int MAX = 2 * 250 + 5;

int N;
string grid[25];
char ans[25][25];

int cnt(int i0, int j0, char c) {
    int n = 0;
    for (int i = i0 - 1; i <= i0 + 1; i++) {
        for (int j = j0 - 1; j <= j0 + 1; j++) {
            if (i >= 0 && i < N && j >= 0 && j < N) {
                n += ans[i][j] == c;
            }
        }
    }
    return n;
}

void flood(int i0, int j0, char c) {
    for (int i = i0 - 1; i <= i0 + 1; i++) {
        for (int j = j0 - 1; j <= j0 + 1; j++) {
            if (i >= 0 && i < N && j >= 0 && j < N) {
                if (ans[i][j] == ' ') {
                    ans[i][j] = c;
                }
            }
        }
    }
}

int main() {
    
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    for (int test = 1; test <= 5; test++) {
        
        FILL(ans, ' ');
        cin >> grid[0];
        N = (int) grid[0].length();
        for (int i = 1; i <= N - 1; i++) {
            cin >> grid[i];
        }
        
        bool done = false;
        while (!done) {
            done = true;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (grid[i][j] != '-') {
                        if (cnt(i, j, 'M') + cnt(i, j, ' ') == grid[i][j] - '0') {
                            flood(i, j, 'M');
                        } else if (cnt(i, j, 'M') == grid[i][j] - '0') {
                            flood(i, j, '.');
                        }
                    }
                }
            }
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (ans[i][j] == ' ') {
                        done = false;
                    }
                }
            }
        }
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << ans[i][j];
            }
            cout << "\n";
        }
        cout << "\n";
    }
    
    return 0;
}
