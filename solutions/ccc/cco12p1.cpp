/*
 Solution to CCO '12 P1 - Choose Your Own Arithmetic by Ava Pun
 Key concepts: brute force backtracking
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const int MAX = 150005;

int W, D, V;
bool work[10];

bool solve(int w, int val) {
    if (w == 0) {
        return val >= 0 && val <= 9 && work[val];
    }
    for (int i = 0; i <= 9; i++) {
        if (work[i]) {
            if (val - i >= 0 && solve(w - 1, val - i)) {
                return 1;
            }
            if (i != 0 && val % i == 0 && solve(w - 1, val / i)) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    
    scanf("%d", &W);
    scanf("%d", &D);
    int n;
    for (int i = 1; i <= D; i++) {
        scanf("%d", &n);
        work[n] = 1;
    }
    scanf("%d", &V);
    while (V--) {
        scanf("%d", &n);
        printf(solve(W, n) ? "Y\n" : "N\n");
    }

    return 0;
}
