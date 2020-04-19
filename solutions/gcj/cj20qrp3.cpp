/*
 Solution to Google Code Jam '20 QR P3 - Parenting Partnering Returns by Ava Pun
 Key concepts: implementation, greedy algorithms
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
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;
const double EPS = 1e-9;

int T, N;
vii events[1441];
bool ans[1005];

int main() {

    scanf("%d", &T);

    for (int test = 1; test <= T; test++) {

        for (int i = 0; i <= 1440; i++) {
            events[i].clear();
        }

        scanf("%d", &N);
        int a, b;
        for (int i = 1; i <= N; i++) {
            scanf("%d%d", &a, &b);
            events[a].pb({1, i});
            events[b].pb({0, i});
        }
        for (int i = 0; i <= 1440; i++) {
            sort(events[i].begin(), events[i].end());
        }

        bool used[] = {0, 0};
        bool imp = 0;
        for (int i = 0; i <= 1440 && !imp; i++) {
            for (auto p : events[i]) {
                if (p.f == 0) {
                    used[ans[p.s]] = 0;
                } else {
                    if (!used[0]) {
                        ans[p.s] = 0;
                        used[0] = 1;
                    } else if (!used[1]) {
                        ans[p.s] = 1;
                        used[1] = 1;
                    } else {
                        imp = 1;
                        break;
                    }
                }
            }
        }

        printf("Case #%d: ", test);
        if (imp) {
            printf("IMPOSSIBLE\n");
        } else {
            for (int i = 1; i <= N; i++) {
                printf(ans[i] ? "C" : "J");
            }
            printf("\n");
        }

    }

    return 0;
}
