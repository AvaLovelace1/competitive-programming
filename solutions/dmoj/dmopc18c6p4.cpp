/*
 Solution to DMOPC '18 Contest 6 P4 - Tank by Ava Pun
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
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;

int N, P, M;
pii def[MAX], res[MAX];
int valP[MAX], valM[MAX];
ll ans[MAX];

inline void solve(pii arr[], int K, int val[]) {
    sort(arr + 1, arr + N + 1);
    sort(val + 1, val + K + 1);
    ll sum = 0;
    ll n = K;
    queue<int> q;
    for (int i = 1; i <= K; i++) {
        q.push(val[i]);
        sum += val[i];
    }
    for (int i = 1; i <= N; i++) {
        while (!q.empty() && q.front() < arr[i].f) {
            sum -= q.front();
            n--;
            q.pop();
        }
        ans[arr[i].s] += sum - arr[i].f * n;
    }
}

int main() {
    
    scanf("%d%d%d", &N, &P, &M);
    for (int i = 1; i <= N; i++) {
        scanf("%d%d", &def[i].f, &res[i].f);
        def[i].s = res[i].s = i;
    }
    for (int i = 1; i <= P; i++) {
        scanf("%d", &valP[i]);
    }
    for (int i = 1; i <= M; i++) {
        scanf("%d", &valM[i]);
    }
    solve(def, P, valP);
    solve(res, M, valM);

    printf("%d\n", (int) (min_element(ans + 1, ans + N + 1) - ans));
    
    return 0;
}
