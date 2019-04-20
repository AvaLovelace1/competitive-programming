/*
 Solution to CCC '14 S5 - Lazy Fox by Ava Pun
 Key concepts: dynamic programming
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
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1e9 + 7;
const int MAX = 2005;

int N;
pii arr[MAX];
vector<piii> events;
int dp[MAX];
vii updates;

inline int distSq(pii a, pii b) {
    return (a.f - b.f) * (a.f - b.f) + (a.s - b.s) * (a.s - b.s);
}

int main() {
    
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d%d", &arr[i].f, &arr[i].s);
    }
    for (int i = 1; i <= N; i++) {
        int d = distSq({0, 0}, arr[i]);
        events.pb({d, {0, i}});
        for (int j = i + 1; j <= N; j++) {
            int d = distSq(arr[i], arr[j]);
            events.pb({d, {i, j}});
        }
    }
    sort(events.begin(), events.end());

    fill(dp, dp + N + 1, 1);
    for (int i = 0; i <= events.size(); i++) {
        if (i == events.size() || (i != 0 && events[i - 1].f != events[i].f)) {
            for (auto p : updates) {
                dp[p.f] = max(dp[p.f], p.s);
            }
            updates.clear();
            if (i == events.size()) {
                break;
            }
        }
        int a = events[i].s.f, b = events[i].s.s;
        updates.pb({a, dp[b] + 1});
        if (a != 0) {
            updates.pb({b, dp[a] + 1});
        }
    }
    printf("%d\n", dp[0] - 1);

    return 0;
}
