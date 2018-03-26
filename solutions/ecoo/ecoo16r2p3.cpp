/*
 Solution to ECOO '16 R2 P3 - BattleShip by Ava Pun
 Key concepts: brute force, implementation
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
const int MAX = 105;

int S, L;
char grid[MAX][MAX];

int main() {
    
    for (int test = 1; test <= 10; test++) {
        
        FILL(grid, 0);
        scanf("%d%d", &S, &L);
        for (int i = 1; i <= S; i++) {
            scanf("%s", grid[i] + 1);
        }
        
        int cnt = 0;
        bool found1, found2;
        
        for (int i = 1; i <= S; i++) {
            for (int j = 1; j + L - 1 <= S; j++) {
                
                found1 = found2 = true;
                if (L == 1) {
                    found2 = false;
                }
                
                for (int k = j; k < j + L && (found1 || found2); k++) {
                    if (grid[i][k] == 'm') {
                        found1 = false;
                    }
                    if (grid[k][i] == 'm') {
                        found2 = false;
                    }
                }
                
                if (grid[i][j - 1] == 'h' || grid[i][j + L] == 'h') {
                    found1 = false;
                }
                if (grid[j - 1][i] == 'h' || grid[j + L][i] == 'h') {
                    found2 = false;
                }
                for (int k = j - 1; k <= j + L && (found1 || found2); k++) {
                    if (grid[i - 1][k] == 'h' || grid[i + 1][k] == 'h') {
                        found1 = false;
                    }
                    if (grid[k][i - 1] == 'h' || grid[k][i + 1] == 'h') {
                        found2 = false;
                    }
                }
                
                cnt += found1;
                cnt += found2;

            }
        }
        
        printf("%d\n", cnt);
        
    }
    
    return 0;
}
