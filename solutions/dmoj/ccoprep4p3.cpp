/*
 Solution to Dynamic MST by Ava Pun
 Key concepts: minimum spanning tree, Kruskal's, square root query bucketing
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
const int MAX = 20005;

int N, M, Q;
int BLOCK_SIZE;
int X[50005], Y[50005], W[50005];
pii quers[50005];
int block[50005];
int blockCnt = 0;
int ranks[2][MAX], par[2][MAX];
struct comp {
    bool operator()(int a, int b) {
        return W[a] == W[b] ? a < b : W[a] < W[b];
    }
};
set<int, comp> maybe, edges;
int poss[50005];
vi idxes;

int Find(int x, int par[]) {
    if (par[x] != x) {
        par[x] = Find(par[x], par);
    }
    return par[x];
}

inline bool Union(int a, int b, int par[], int ranks[]) {
    a = Find(a, par);
    b = Find(b, par);
    if (a == b) {
        return 0;
    } else {
        if (ranks[a] > ranks[b]) {
            par[b] = a;
        } else {
            par[a] = b;
            if (ranks[a] == ranks[b]) {
                ranks[b]++;
            }
        }
        return 1;
    }
}

inline void reset(int par[], int ranks[]) {
    for (int i = 1; i <= N; i++) {
        par[i] = i;
        ranks[i] = 0;
    }
}

int main() {
    
    scanf("%d%d%d", &N, &M, &Q);
    BLOCK_SIZE = sqrt(Q);
    for (int i = 1; i <= M; i++) {
        scanf("%d%d%d", &X[i], &Y[i], &W[i]);
        edges.insert(i);
    }

    for (int i = 1; i <= Q; i++) {
        scanf("%d%d", &quers[i].f, &quers[i].s);
    }

    for (int l = 1; l <= Q; l += BLOCK_SIZE) {

        blockCnt++;
        int r = min(Q, l + BLOCK_SIZE - 1);
        maybe.clear();
        for (int i = l; i <= r; i++) {
            block[quers[i].f] = blockCnt;
            // Any changed edge might be in an MST of this block.
            maybe.insert(quers[i].f);
        }

        // MST of G - E. Edges not in this MST are guaranteed
        // not to be in any MST of this block.
        int cnt = 0;
        reset(par[0], ranks[0]);
        for (int i : edges) {
            if (block[i] != blockCnt && Union(X[i], Y[i], par[0], ranks[0])) {
                poss[++cnt] = i;
            }
        }

        // MST of G with all E already connected. Edges in this
        // MST are guaranteed to be in every MST of this block.
        ll ans = 0;
        reset(par[1], ranks[1]);
        reset(par[0], ranks[0]);
        for (int i = l; i <= r; i++) {
            Union(X[quers[i].f], Y[quers[i].f], par[1], ranks[1]);
        }
        for (int i = 1; i <= cnt; i++) {
            if (Union(X[poss[i]], Y[poss[i]], par[1], ranks[1])) {
                Union(X[poss[i]], Y[poss[i]], par[0], ranks[0]);
                ans += W[poss[i]];
            } else {
                maybe.insert(poss[i]);
            }
        }
  
        idxes.clear();
        for (int i = 1; i <= N; i++) {
            idxes.pb(Find(i, par[0]));
        }
        sort(idxes.begin(), idxes.end());
        idxes.erase(unique(idxes.begin(), idxes.end()), idxes.end());

        for (int i = l; i <= r; i++) {
            maybe.erase(quers[i].f);
            edges.erase(quers[i].f);
            W[quers[i].f] = quers[i].s;
            maybe.insert(quers[i].f);
            edges.insert(quers[i].f);
            ll tmp = 0;
            for (int j : idxes) {
                par[1][j] = j;
                ranks[1][j] = 0;
            }
            for (int j : maybe) {
                if (Union(Find(X[j], par[0]), Find(Y[j], par[0]), par[1], ranks[1])) {
                    tmp += W[j];
                }
            }
            printf("%lld\n", ans + tmp);
        }
    }

    return 0;
}
