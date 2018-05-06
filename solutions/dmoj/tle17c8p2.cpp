/*
 Solution to TLE '17 Contest 8 P2 - Ship Defense by Ava Pun
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
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;

int H, D, E;
pii def[10];
int events[1005];

int main() {

    scanf("%d%d%d", &H, &D, &E);
    
    for (int i = 1; i <= D; i++) {
        scanf("%d%d", &def[i].f, &def[i].s);
    }
    int t, l, x;
    for (int i = 1; i <= E; i++) {
        scanf("%d%d%d", &t, &l, &x);
        events[t] += x;
        events[t + l] -= x;
    }
    for (int i = 1; i < 1005; i++) {
        events[i] += events[i - 1];
    }
    double hh = H;
    for (int i = 0; i < 1005; i++) {
        double minN = events[i];
        for (int j = 1; j <= D; j++) {
            minN = min(minN, max(0, events[i] - def[j].s) * (1 - (double) def[j].f / 100));
        }
        hh -= minN;
    }
    
    if (hh < 1e-7) {
        printf("DO A BARREL ROLL!\n");
    } else {
        printf("%.2lf\n", hh);
    }
    
    return 0;
}
