/*
 Solution to WC18 #1 - Reach for the Top by Ava Pun
 Key concepts: BFS, difference array
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
const int MAX = 2e6 + 5;

int H, J, N;
int bad[MAX];
int dist[MAX];

int main() {
    
    scanf("%d%d%d", &H, &J, &N);
    
    int l, r;
    while (N--) {
        scanf("%d%d", &l, &r);
        bad[l]++, bad[r + 1]--;
    }
    for (int i = 1; i <= 2 * H; i++) {
        bad[i] += bad[i - 1];
    }
    
    queue<int> q;
    FILL(dist, INF);
    q.push(0);
    dist[0] = 0;
    
    int prevMax = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u < H) {
            if (!bad[u + J] && dist[u + J] == INF) {
                dist[u + J] = dist[u] + 1;
                q.push(u + J);
            }
            for (int i = prevMax + 1; i < u; i++) {
                if (!bad[i] && dist[i] == INF) {
                    dist[i] = dist[u] + 1;
                    q.push(i);
                }
            }
            prevMax = max(prevMax, u);
        }
    }
    
    int ans = *min_element(dist + H, dist + 2 * H + 1);
    printf("%d\n", ans == INF ? -1 : ans);
    
    return 0;
}
