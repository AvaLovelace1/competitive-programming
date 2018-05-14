/*
 Solution to WC17 Finals - Ultimatum by Ava Pun
 Key concepts: binary indexed tree
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
typedef pair<pii, pii> piiii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;

int N, Q;
piii arr[MAX];
ll totbit[MAX], prevbit[2][MAX], currbit[2][MAX];
piiii quers[MAX];
double ans[MAX];

void update(int pos, int x, ll bit[]) {
    for (int i = pos; i <= N; i += i & -i) {
        bit[i] += x;
    }
}

void update(int pos, int x, ll bit[][MAX]) {
    update(pos, x, bit[0]);
    update(pos, x / abs(x), bit[1]);
}

ll query(int pos, ll bit[]) {
    ll ans = 0;
    for (int i = pos; i > 0; i -= i & -i) {
        ans += bit[i];
    }
    return ans;
}

ll query(int l, int r, ll bit[]) {
    return query(r, bit) - query(l - 1, bit);
}

int main() {
    
    scanf("%d", &N);
    int n;
    for (int i = 1; i <= N; i++) {
        scanf("%d%d", &arr[i].f, &n);
        arr[i].s = {n, i};
        update(i, n, totbit);
    }
    sort(arr + 1, arr + N + 1, greater<piii>());
    
    scanf("%d", &Q);
    for (int i = 1; i <= Q; i++) {
        scanf("%d%d%d", &quers[i].f.f, &quers[i].s.f, &quers[i].s.s);
        quers[i].f.s = i;
    }
    sort(quers + 1, quers + Q + 1);
    
    int x, l, r, idx;
    int ppos = 1, cpos = 1;
    
    for (int i = 1; i <= Q; i++) {
        
        x = quers[i].f.f, l = quers[i].s.f, r = quers[i].s.s, idx = quers[i].f.s;
        if (x) {
            while (arr[ppos].f > arr[x].f && ppos <= N) {
                update(arr[ppos].s.s, arr[ppos].s.f, prevbit);
                if (ppos < cpos) {
                    update(arr[ppos].s.s, -arr[ppos].s.f, currbit);
                } else {
                    cpos++;
                }
                ppos++;
            }
            while (arr[cpos].f == arr[x].f && cpos <= N) {
                update(arr[cpos].s.s, arr[cpos].s.f, currbit);
                cpos++;
            }
        }
        
        ll rngtot = query(l, r, totbit);
        ll prevnn = query(1, N, prevbit[1]);
        ll prevtot = query(1, N, prevbit[0]) - query(l, r, prevbit[0]);
        ll currnn = query(1, N, currbit[1]);
        ll currn = currnn - query(l, r, currbit[1]);
        ll currtot = query(1, N, currbit[0]) - query(l, r, currbit[0]);
        double avg = (double) currtot / currn;
        double perc = (double) currn / currnn;
        
        if (!currn) {
            ans[idx] = (double) rngtot + prevtot;
        } else {
            ans[idx] = rngtot + prevtot + (x - prevnn) * perc * avg;
        }
        
    }
    
    for (int i = 1; i <= Q; i++) {
        printf("%lf\n", ans[i]);
    }
    
    return 0;
}
