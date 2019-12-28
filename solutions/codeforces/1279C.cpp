/*
 Solution to Stack of Presents by Ava Pun
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
const int MAX = 1e5 + 5;
const double EPS = 1e-9;

int T;
int N, M;
int arr1[MAX], arr2[MAX];
int pos[MAX];

int main() {

    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &N, &M);
        for (int i = 1; i <= N; i++) {
            scanf("%d", &arr1[i]);
            pos[arr1[i]] = i;
        }
        for (int i = 1; i <= M; i++) {
            scanf("%d", &arr2[i]);
        }
        ll ans = 0;
        int deepest = 0, numAbove = 0;
        for (int i = 1; i <= M; i++) {
            if (pos[arr2[i]] > deepest) {
                numAbove += pos[arr2[i]] - deepest - 1;
                deepest = pos[arr2[i]];
                ans += 2 * numAbove + 1;
            } else {
                ans++;
                numAbove--;
            }
        }
        printf("%lld\n", ans);
    }


    return 0;
}
