/*
 Solution to BOI 2007 P3 - Sound by Ava Pun
 Key concepts: monoqueue
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
const int MAX = 1e5 + 5;

int N, M, C;
deque<pii> minQ, maxQ;

int main() {
    
    scanf("%d%d%d", &N, &M, &C);
    bool found = false;
    int n;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &n);
        while (!minQ.empty() && minQ.front().s <= i - M) {
            minQ.pop_front();
        }
        while (!minQ.empty() && minQ.back().f > n) {
            minQ.pop_back();
        }
        minQ.pb({n, i});
        while (!maxQ.empty() && maxQ.front().s <= i - M) {
            maxQ.pop_front();
        }
        while (!maxQ.empty() && maxQ.back().f < n) {
            maxQ.pop_back();
        }
        maxQ.pb({n, i});
        if (maxQ.front().f - minQ.front().f <= C && i - M + 1 > 0) {
            found = true;
            printf("%d\n", i - M + 1);
        }
    }
    if (!found) {
        printf("NONE\n");
    }

    return 0;
}
