/*
 Solution to TLE '17 Contest 8 P1 - Artificial Intelligence by Ava Pun
 Key concepts: implementation, math
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
const int MAX = 5e4 + 5;

int N;

int main() {
    
    scanf("%d", &N);
    int x, y;
    double m = INF;
    bool ans = 1;
    while (N--) {
        scanf("%d%d", &x, &y);
        if (x == 0) {
            ans &= y == 0;
        } else {
            if (m == INF) {
                m = (double) y / x;
            } else {
                if (abs((double) y / x - m) > 1e-7) {
                    ans = 0;
                }
            }
        }
    }
    printf(ans ? "yes\n" : "no\n");
    
    return 0;
}
