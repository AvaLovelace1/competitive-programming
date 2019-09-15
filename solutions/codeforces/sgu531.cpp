/*
 Solution to Bonnie and Clyde by Ava Pun
 Key concepts: prefix max array, two pointers
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
const int MAX = 2e5 + 5;
const double EPS = 1e-9;

int N, D;
pii arr[MAX], pref[MAX];

int main() {
    
    scanf("%d%d", &N, &D);
    for (int i = 1; i <= N; i++) {
        scanf("%d%d", &arr[i].s, &arr[i].f);
    }
    for (int i = 1; i <= N; i++) {
        pii tmp = {arr[i].f, i};
        pref[i] = max(tmp, pref[i - 1]);
    }
    int l = 1;
    int ans = 0, b1 = 0, b2 = 0;
    for (int i = 1; i <= N; i++) {
        while (arr[i].s - arr[l].s >= D) {
            l++;
        }
        if (l > 1 && pref[l - 1].f + arr[i].f > ans) {
            ans = pref[l - 1].f + arr[i].f;
            b1 = pref[l - 1].s;
            b2 = i;
        }
    }
    if (ans == 0) {
        printf("-1 -1\n");
    } else {
        printf("%d %d\n", b1, b2);
    }

    return 0;
}
