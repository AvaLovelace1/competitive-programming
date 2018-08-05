/*
 Solution to All Green by Ava Pun
 Key concepts: brute force, greedy algorithms
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<pii, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;

int D, G;
int p[11], c[11];

int main() {
    
    scanf("%d%d", &D, &G);
    G /= 100;
    for (int i = 1; i <= D; i++) {
        scanf("%d%d", &p[i], &c[i]);
        c[i] /= 100;
    }
    
    int best = INF;
    for (int m = 0; m < (1 << D); m++) {
        int curr = 0, currN = 0;
        for (int i = 1; i <= D; i++) {
            if (m & (1 << (i - 1))) {
                curr += i * p[i] + c[i];
                currN += p[i];
            }
        }
        for (int i = D; i >= 1 && curr < G; i--) {
            if (!(m & (1 << (i - 1)))) {
                int n = min(p[i] - 1, (G - curr + 1) / i);
                curr += i * n;
                currN += n;
            }
        }
        if (curr >= G) {
            best = min(best, currN);
        }
    }
    printf("%d\n", best);
    
    return 0;
}
