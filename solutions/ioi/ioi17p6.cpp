/*
 Solution to IOI '17 P6 - Ancient Books by Ava Pun
 Key concepts: ad hoc, greedy algorithms
 */

#include <bits/stdc++.h>

using namespace std;

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
const int MAX = 1e6 + 5;

int N, S;
int arr[MAX], cycle[MAX], ls[MAX], rs[MAX];
bool vis[MAX];

inline void extend(int &l, int &r) {
    int minL = min(ls[cycle[l]], ls[cycle[r]]);
    int maxR = max(rs[cycle[l]], rs[cycle[r]]);
    while (l > minL || r < maxR) {
        if (l > minL) {
            l--;
            minL = min(minL, ls[cycle[l]]);
            maxR = max(maxR, rs[cycle[l]]);
        } else {
            r++;
            minL = min(minL, ls[cycle[r]]);
            maxR = max(maxR, rs[cycle[r]]);
        }
    }
}

inline ll solveL(int r, int minL, bool &found, int &tmpL, int &tmpR) {
    ll ans = 0;
    while (tmpL > minL) {
        ans += 2;
        tmpL--;
        extend(tmpL, tmpR);
        if (tmpR > r) {
            found = 1;
            return ans;
        }
    }
    return ans;
}

inline ll solveR(int l, int maxR, bool &found, int &tmpL, int &tmpR) {
    ll ans = 0;
    while (tmpR < maxR) {
        ans += 2;
        tmpR++;
        extend(tmpL, tmpR);
        if (tmpL < l) {
            found = 1;
            return ans;
        }
    }
    return ans;
}

long long minimum_walk(std::vector<int> p, int s) {
    
    N = (int) p.size(), S = s;
    for (int i = 0; i < N; i++) {
        arr[i] = p[i];
    }
    
    int minL = S, maxR = S;
    ll ans = 0;
    FILL(ls, INF);
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (!vis[i]) {
            int u = i;
            while (!vis[u]) {
                vis[u] = 1;
                cycle[u] = cnt;
                ls[cnt] = min(ls[cnt], u);
                rs[cnt] = max(rs[cnt], u);
                ans += abs(u - arr[u]);
                u = arr[u];
            }
            if (ls[cnt] != rs[cnt]) {
                minL = min(minL, ls[cnt]);
                maxR = max(maxR, rs[cnt]);
            }
            cnt++;
        }
    }
    
    int currL = S, currR = S;
    extend(currL, currR);
    while (currL > minL || currR < maxR) {
        int tmpL1 = currL, tmpR1 = currR, tmpL2 = currL, tmpR2 = currR;
        bool found1 = 0, found2 = 0;
        ll costL = solveL(currR, minL, found1, tmpL1, tmpR1);
        ll costR = solveR(currL, maxR, found2, tmpL2, tmpR2);
        if (!found1 || !found2) {
            ans += costL + costR;
        } else {
            ans += min(costL, costR);
        }
        currL = min(tmpL1, tmpL2);
        currR = max(tmpR1, tmpR2);
        extend(currL, currR);
    }
    
    return ans;
}

int main() {

    int n, s;
    assert(2 == scanf("%d %d", &n, &s));
    
    vector<int> p((unsigned) n);
    for(int i = 0; i < n; i++)
        assert(1 == scanf("%d", &p[(unsigned) i]));
    
    long long res = minimum_walk(p, s);
    printf("%lld\n", res);
    
    return 0;
}
