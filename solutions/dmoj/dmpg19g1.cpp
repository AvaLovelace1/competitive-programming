/*
 Solution to DMPG '19 G1 - Camera Calibration Challenge by Ava Pun
 Key concepts: sorting, two pointers
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
const int MAX = 1e6 + 5;

int N, M, Q;
int arr[MAX];
pii quers[MAX];
ll ans[MAX];

inline ll ceilDiv(ll a, ll b) {
    return (a + b - 1) / b;
}

int main() {
    
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            scanf("%d", &arr[M * (i - 1) + j]);
        }
    }
    
    scanf("%d", &Q);
    for (int i = 1; i <= Q; i++) {
        scanf("%d", &quers[i].f);
        quers[i].s = i;
    }
    sort(quers + 1, quers + Q + 1);
    
    ll sum = 0;
    int minN = arr[1];
    ll ones = 0;
    sort(arr + 1, arr + N * M + 1, greater<int>());
    
    queue<int> q;
    for (int i = 1; i <= N * M; i++) {
        q.push(arr[i]);
        sum += arr[i];
        minN = min(minN, arr[i]);
    }
    
    ll e = 0;
    for (int i = 1; i <= Q; i++) {
        if (quers[i].f == 1e6) {
            e = max(e, ceilDiv(1e12, minN));
        } else {
            e = max(e, ceilDiv(((ll) quers[i].f * N * M - ones) * 1000000, sum));
            while (!q.empty() && q.front() * e > 1e12) {
                sum -= q.front();
                ones += 1000000;
                q.pop();
                e = max(e, ceilDiv(((ll) quers[i].f * N * M - ones) * 1000000, sum));
            }
        }
        ans[quers[i].s] = e;
    }

    for (int i = 1; i <= Q; i++) {
        printf("%lld\n", ans[i]);
    }
    
    return 0;
}
