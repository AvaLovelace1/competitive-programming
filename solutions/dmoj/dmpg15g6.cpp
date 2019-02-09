/*
 Solution to DMPG '15 G6 - Yōkan by Ava Pun
 Key concepts: square root tricks
 */
 
#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back

typedef pair<int, int> pii;
typedef pair<pii, int> piii;
const int MAX = 2e5 + 5;

int N, M, Q, BLOCK;
int arr[MAX];
pii vals[MAX];
vector<int> pos[MAX];
map<int, int> mp;

int main() {
    
    scanf("%d%d", &N, &M);
    BLOCK = sqrt(N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
        pos[arr[i]].pb(i);
    }
    for (int i = 1; i <= M; i++) {
        vals[i] = {pos[i].size(), i};
        sort(pos[i].begin(), pos[i].end());
    }
    sort(vals + 1, vals + M + 1, greater<pii>());
    
    scanf("%d", &Q);
    int l, r;
    for (int i = 1; i <= Q; i++) {
        scanf("%d%d", &l, &r);
        int L = r - l + 1;
        if (L < 3 * BLOCK) {
            mp.clear();
            for (int j = l; j <= r; j++) {
                mp[arr[j]]++;
            }
            int tmp = 0;
            for (auto p : mp) {
                tmp += (3 * p.s >= L) + (3 * p.s >= 2 * L);
            }
            printf(tmp >= 2 ? "YES\n" : "NO\n");
        } else {
            int tmp = 0;
            for (int j = 1; j <= M && vals[j].f >= BLOCK; j++) {
                int n = (int) (upper_bound(pos[vals[j].s].begin(), pos[vals[j].s].end(), r) -
                               lower_bound(pos[vals[j].s].begin(), pos[vals[j].s].end(), l));
                tmp += (3 * n >= L) + (3 * n >= 2 * L);
            }
            printf(tmp >= 2 ? "YES\n" : "NO\n");
        }
    }
    return 0;
}
