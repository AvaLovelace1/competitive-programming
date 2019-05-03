/*
 Solution to DMOPC '18 Contest 4 P0 - Dr. Henri and Seeing Stars by Ava Pun
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
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

int R, X, Y;
int x[3], y[3], m[3];

int main() {
    
    scanf("%d%d%d", &R, &X, &Y);
    int maxN = 0, maxM = INF;
    for (int i = 0; i < 3; i++) {
        scanf("%d%d%d", &x[i], &y[i], &m[i]);
        if (m[i] < maxM) {
            maxM = m[i];
            maxN = i;
        }
    }
    printf((x[maxN] - X) * (x[maxN] - X) + (y[maxN] - Y) * (y[maxN] - Y) < R * R ? "What a beauty!\n" : "Time to move my telescope!\n");
    
    return 0;
}
