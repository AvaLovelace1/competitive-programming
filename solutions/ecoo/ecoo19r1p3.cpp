/*
 Solution to ECOO '19 R1 P3 - Side Scrolling Simulator by Ava Pun
 Key concepts: implementation
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
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1e9 + 7;
const int MAX = 1e7 + 5;

int J, W, H;
char grid[105][15];
int S, T;

int main() {
    
    for (int test = 1; test <= 10; test++) {
        scanf("%d%d%d", &J, &W, &H);
        for (int i = H; i >= 1; i--) {
            for (int j = 1; j <= W; j++) {
                scanf(" %c", &grid[j][i]);
                if (grid[j][i] == 'L') {
                    S = j;
                } else if (grid[j][i] == 'G') {
                    T = j;
                }
            }
        }
        int ans = -1;
        for (int i = S; i <= T && ans == -1; i++) {
            if (grid[i][2] == '@') {
                int h = 2;
                while (h <= H && h <= 2 + J && grid[i][h] == '@') {
                    h++;
                }
                bool good = h <= H && h <= 2 + J && grid[i][h] != '@';
                for (int j = 2; j <= h && good; j++) {
                    if (grid[i - 1][j] == '@' || grid[i + 1][j] == '@') {
                        good = 0;
                    }
                }
                if (!good) {
                    ans = i;
                }
            }
        }
        if (ans == -1) {
            printf("CLEAR\n");
        } else {
            printf("%d\n", ans);
        }
    }
    
    return 0;
}
