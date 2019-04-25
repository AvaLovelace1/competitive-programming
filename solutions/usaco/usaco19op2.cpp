/*
 Solution to USACO '19 Open P2 - Compound Escape by Ava Pun
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
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1e9 + 7;
const int MAX = 30000 + 5;

int N, K;
int arrH[MAX][10], arrV[MAX][10];
pair<ll, int> dp[2][10][215];
int mp[10], firstLoc[10];
int sorted[] = {0, 1, 2, 3, 4, 5, 6};
vector<string> valid;
int nxtDP[10][215][2][2];

inline bool comp(int a, int b) {
    if (mp[a] == mp[b]) {
        return firstLoc[a] < firstLoc[b];
    }
    return mp[a] > mp[b];
}

inline string conv(string m) {
    for (int i = 1; i <= K; i++) {
        mp[i] = firstLoc[i] = 0;
    }
    for (int i = 1; i <= K; i++) {
        mp[m[i] - '0']++;
        if (firstLoc[m[i] - '0'] == 0) {
            firstLoc[m[i] - '0'] = i;
        }
    }
    sort(sorted + 1, sorted + K + 1, comp);
    for (int i = 1; i <= K; i++) {
        mp[sorted[i]] = i;
    }
    for (int i = 1; i <= K; i++) {
        m[i] = mp[m[i] - '0'] + '0';
    }
    return m;
}

inline void gen(int n, string str) {
    if (n == K) {
        valid.pb(conv(str));
        return;
    }
    for (int i = 1; i <= K; i++) {
        gen(n + 1, str + (char) ('0' + i));
    }
}

inline int getIdx(string str) {
    str = conv(str);
    return (int) (lower_bound(valid.begin(), valid.end(), str) - valid.begin());
}

inline int getNxtDP(int j, int k, bool hor, bool ver) {
    string str = valid[k];
    if (!ver) {
        // must take vertical if will be disconnected otherwise
        if (count(str.begin(), str.end(), str[j % K + 1]) == 1) {
            return -1;
        }
    }
    if (ver && hor) {
        // take both edges
        for (int i = 1; i <= K; i++) {
            if (str[i] == valid[k][j % K + 1]) {
                str[i] = valid[k][j];
            }
        }
    } else if (ver) {
        // take vertical
    } else if (hor) {
        // take horizontal
        str[j % K + 1] = str[j];
    } else {
        // don't take either edge
        if (count(str.begin(), str.end(), K + '0') == 0) {
            str[j % K + 1] = K + '0';
        }
    }
    return getIdx(str);
}

inline void comb(pair<ll, int> &a, pair<ll, int> b, int cost) {
    b.f += cost;
    if (b.f < a.f) {
        a = b;
    } else if (b.f == a.f) {
        a.s = (a.s + b.s) % MOD;
    }
}

inline void solve(int i, int j, int k, bool hor, bool ver) {
    int nxt = nxtDP[j][k][hor][ver];
    if (nxt == -1) {
        return;
    }
    if (j == K) {
        comb(dp[!(i & 1)][1][nxt], dp[i & 1][j][k], arrV[i + 1][1] * ver);
    } else {
        comb(dp[i & 1][j + 1][nxt], dp[i & 1][j][k], arrH[i][j + 1] * hor + arrV[i][j + 1] * ver);
    }
}

int main() {
    
    freopen("escape.in", "r", stdin);
    freopen("escape.out", "w", stdout);
    
    scanf("%d%d", &N, &K);
    for (int i = 1; i <= N; i++) {
        for (int j = 2; j <= K; j++) {
            scanf("%d", &arrH[i][j]);
        }
    }
    for (int i = 1; i <= K; i++) {
        for (int j = 2; j <= N; j++) {
            scanf("%d", &arrV[j][i]);
        }
    }
    
    gen(0, "0");
    sort(valid.begin(), valid.end());
    valid.erase(unique(valid.begin(), valid.end()), valid.end());
    for (int k = 0; k < valid.size(); k++) {
        for (int j = 1; j <= K; j++) {
            for (int h = 0; h <= 1; h++) {
                for (int v = 0; v <= 1; v++) {
                    nxtDP[j][k][h][v] = getNxtDP(j, k, h, v);
                }
            }
        }
    }
    
    for (int j = 1; j <= K; j++) {
        for (int k = 0; k < valid.size(); k++) {
            dp[1][j][k] = {INFL, 0};
        }
    }
    string separate = "0";
    for (int i = 1; i <= K; i++) {
        separate += i + '0';
    }
    dp[1][1][getIdx(separate)] = {0, 1};
    for (int j = 1; j <= K - 1; j++) {
        for (int k = 0; k < valid.size(); k++) {
            solve(1, j, k, 0, 1);
            solve(1, j, k, 1, 1);
        }
    }

    for (int i = 2; i <= N; i++) {
        for (int j = 1; j <= K; j++) {
            for (int k = 0; k < valid.size(); k++) {
                dp[i & 1][j][k] = {INFL, 0};
            }
        }
        for (int k = 0; k < valid.size(); k++) {
            solve(i - 1, K, k, 0, 0);
            solve(i - 1, K, k, 0, 1);
        }
        for (int j = 1; j <= K - 1; j++) {
            for (int k = 0; k < valid.size(); k++) {
                solve(i, j, k, 0, 0);
                solve(i, j, k, 0, 1);
                solve(i, j, k, 1, 0);
                solve(i, j, k, 1, 1);
            }
        }
    }
    printf("%d\n", dp[N & 1][K][0].s);
    
    return 0;
}
