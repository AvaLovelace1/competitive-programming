/*
 Solution to ECOO '19 R2 P2 - Pizza by Ava Pun
 Key concepts: geometry
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
const int MAX = 5005;

int N;
pii arr[MAX];
set<pair<ll, ll>> mp;

inline ll distSq(int idxA, int idxB) {
    pii a = arr[idxA], b = arr[idxB];
    return (ll) (a.f - b.f) * (a.f - b.f) + (ll) (a.s - b.s) * (a.s - b.s);
}

inline bool checkRef(int p, int l, int r) {
    int ref = (l - (p - l) - 1 + N) % N + 1;
    return distSq(p, l) == distSq(ref, l) && distSq(p, r) == distSq(ref, r);
}

inline int solve() {
    if (N & 1) {
        return 0;
    }
    int ans = 0;
    for (int l = 1; l <= N / 2; l++) {
        bool good = 1;
        int r = l + N / 2;
        mp.clear();
        for (int i = l + 1; i <= r - 1; i++) {
            mp.insert({distSq(i, l), distSq(i, r)});
        }
        for (int i = l + 1; i <= r - 1; i++) {
            if (mp.find({distSq((i + N / 2 - 1 + N) % N + 1, l), distSq((i + N / 2 - 1 + N) % N + 1, r)}) == mp.end()) {
                good = 0;
                break;
            }
        }
        ans += good;
    }
    return ans;
}

int main() {
    
    for (int test = 1; test <= 10; test++) {
        scanf("%d", &N);
        for (int i = 1; i <= N; i++) {
            scanf("%d%d", &arr[i].f, &arr[i].s);
        }
        printf("%d\n", solve());
    }
    
    return 0;
}
