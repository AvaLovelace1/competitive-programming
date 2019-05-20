/*
 Solution to GCC '16 P1 - Watching Anime by Ava Pun
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
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
const int MAX = 1e4 + 5;

int N, A, C;
vii events;

int main() {

    scanf("%d%d%d", &N, &A, &C);
    int a, b;
    for (int i = 1; i <= A; i++) {
        scanf("%d%d", &a, &b);
        events.pb({a, 1});
        events.pb({b + 1, -1});
    }
    for (int i = 1; i <= C; i++) {
        scanf("%d%d", &a, &b);
        events.pb({a, 2});
        events.pb({b + 1, -2});
    }
    sort(events.begin(), events.end());

    int cntA = 0, cntC = 0;
    int pre = 1;
    int ans = 0;
    for (int i = 0; i < events.size(); i++) {
        int x = events[i].f, t = events[i].s;
        ans += (x - pre) * (cntA > 0 && cntC == 0);
        if (t == 1) {
            cntA++;
        } else if (t == -1) {
            cntA--;
        } else if (t == 2) {
            cntC++;
        } else {
            cntC--;
        }
        pre = x;
    }
    printf("%d\n", ans);

    return 0;
}
