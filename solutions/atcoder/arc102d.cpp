/*
 Solution to All Your Paths are Different Lengths by Ava Pun
 Key concepts: graph theory, constructive algorithms
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
const int MAX = 1e6 + 5;

int N;
int L;
vector<piii> edges;

int main() {

    scanf("%d", &L);
    N = sizeof(int) * 8 - __builtin_clz(L);
    int cnt = N;
    while ((L >> 1) > 0) {
        if (L & 1) {
            edges.pb({{1, cnt}, L - 1});
        }
        edges.pb({{cnt - 1, cnt}, L >> 1});
        edges.pb({{cnt - 1, cnt}, 0});
        L >>= 1;
        cnt--;
    }
    printf("%d %d\n", N, (int) edges.size());
    for (auto e : edges) {
        printf("%d %d %d\n", e.f.f, e.f.s, e.s);
    }

    return 0;
}
