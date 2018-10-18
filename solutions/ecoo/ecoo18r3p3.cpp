/*
 Solution to ECOO '18 R3 P3 - Currency Exchange by Ava Pun
 Key concepts: Bellman-Ford
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
const int MAX = 5000 + 5;

int N, M, D;
vector<pair<int, double>> adj[MAX];
double dist[MAX];

int main() {
    
    for (int test = 1; test <= 10; test++) {

        scanf("%d%d%d", &N, &M, &D);
        for (int i = 1; i <= N; i++) {
            adj[i].clear();
        }
        int a, b;
        double d;
        for (int i = 1; i <= M; i++) {
            scanf("%d%d%lf", &a, &b, &d);
            adj[a].pb({b, -log10(d)});
        }

        fill(dist, dist + N + 1, -INF);
        dist[1] = log10(D);
        bool cycle = 0;
        for (int i = 1; i <= N; i++) {
            for (int u = 1; u <= N; u++) {
                for (auto e : adj[u]) {
                    int v = e.f;
                    double w = e.s;
                    if (dist[u] != -INF && dist[u] + w - dist[v] > 1e-7) {
                        if (i == N && v == N) {
                            cycle = 1;
                        }
                        dist[v] = dist[u] + w;
                    }
                }
            }
        }

        double ans = pow(10, dist[N]);
        if (ans > 1e9 || cycle) {
            printf("Billionaire!\n");
        } else {
            printf("%.2lf\n", ans);
        }
    }

    return 0;
}
