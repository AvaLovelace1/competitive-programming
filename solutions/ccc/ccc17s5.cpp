/*
 Solution to CCC '17 S5 - RMT by Ava Pun
 Key concepts: square root decomposition
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
const int MAX = 150005;

int N, M, Q;
int BLOCK;
int line[MAX], arr[MAX], posn[MAX];
vi lines[MAX];
int sum[400];
int moved[MAX];
vi bounds[MAX];

inline int getVal(int pos) {
    if (pos == -1) {
        return 0;
    }
    int n = line[pos];
    return arr[lines[n][(posn[pos] - moved[n] % lines[n].size() + lines[n].size()) % lines[n].size()]];
}

inline int query(int l, int r) {
    int ret = 0;
    while (l % BLOCK != 0 && l <= r) {
        ret += getVal(l);
        l++;
    }
    while (r % BLOCK != BLOCK - 1 && r >= l) {
        ret += getVal(r);
        r--;
    }
    while (l <= r) {
        ret += sum[l / BLOCK];
        l += BLOCK;
    }
    return ret;
}

inline void update(int n) {
    for (int i = 0; i < bounds[n].size(); i++) {
        int val = getVal(bounds[n][i]);
        sum[bounds[n][i] / BLOCK] -= val;
        sum[bounds[n][(i + 1) % bounds[n].size()] / BLOCK] += val;
    }
    moved[n]++;
}

int main() {
    
    scanf("%d%d%d", &N, &M, &Q);
    BLOCK = sqrt(N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &line[i]);
        line[i]--;
        lines[line[i]].pb(i);
        posn[i] = lines[line[i]].size() - 1;
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    for (int l = 0; l < N; l += BLOCK) {
        int r = min(N - 1, l + BLOCK - 1);
        for (int i = l; i <= r; i++) {
            sum[l / BLOCK] += arr[i];
            int n = line[i];
            if (bounds[n].empty() || bounds[n].back() / BLOCK != l / BLOCK) {
                bounds[n].pb(i);
            } else {
                bounds[n][bounds[n].size() - 1] = i;
            }
        }
    }

    int t, a, b;
    for (int i = 0; i < Q; i++) {
        scanf("%d", &t);
        if (t == 1) {
            scanf("%d%d", &a, &b);
            a--, b--;
            printf("%d\n", query(a, b));
        } else {
            scanf("%d", &a);
            a--;
            update(a);
        }
    }

    return 0;
}
