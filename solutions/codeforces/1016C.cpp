/*
 Solution to Vasya And The Mushrooms by Ava Pun
 Key concepts: prefix sum array
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<pii, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 3e5 + 5;

int N;
int arr[3][MAX];
ll pref[3][3][MAX];

inline ll query0(int r, int i, int j, int t) {
    if (j < i) {
        swap(i, j);
    }
    return (pref[0][r][j] - pref[0][r][i - 1]) * t;
}

inline ll query(int r, int i, int j) {
    int k = 1;
    ll ans = 0;
    if (j < i) {
        k = 2;
    } else {
        ans = -query0(r, i, j, i - 1);
    }
    ans += pref[k][r][j] - pref[k][r][i + (j < i ? 1 : -1)];
    return ans;
}

int main() {
    
    scanf("%d", &N);
    for (int i = 1; i <= 2; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    
    for (int i = 1; i <= 2; i++) {
        for (int j = 1; j <= N; j++) {
            pref[0][i][j] = pref[0][i][j - 1] + (ll) arr[i][j];
        }
        for (int j = 1; j <= N; j++) {
            pref[1][i][j] = pref[1][i][j - 1] + (ll) arr[i][j] * (j - 1);
        }
        for (int j = N; j >= 1; j--) {
            pref[2][i][j] = pref[2][i][j + 1] + (ll) arr[i][j] * (N - j);
        }
    }
    
    ll best = query(1, 1, N) + query(2, N, 1) + query0(2, 1, N, N), curr = 0;
    int r = 1, c = 1;
    for (int i = 0; i < 2 * N; i++) {
        curr += (ll) arr[r][c] * i;
        i++;
        r = (r & 1) + 1;
        curr += (ll) arr[r][c] * i;
        ll add = query(r, c + 1, N) + query0(r, c + 1, N, i + 1);
        int t = i + 1 + (N - c);
        add += query((r & 1) + 1, N, c + 1) + query0((r & 1) + 1, c + 1, N, t);
        best = max(best, curr + add);
        c++;
    }
    printf("%lld\n", best);
    
    return 0;
}
