/*
 Solution to IOI '16 P1 - Detecting Molecules by Ava Pun
 Key concepts: greedy algorithms
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
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;

int N, L, U, W[MAX], ans[MAX];
pii arr[MAX];

int find_subset(int l, int u, int w[], int n, int result[]) {
    
    for (int i = 0; i < n; i++) {
        arr[i] = {w[i], i};
    }
    sort(arr, arr + n);
    
    ll sum = 0;
    int i = 0, j = 0;
    for (; i < n; i++) {
        sum += arr[i].f;
        while (sum > u && j < n && j < i) {
            sum -= arr[j].f;
            j++;
        }
        if (sum >= l && sum <= u) {
            int cnt = i - j + 1;
            for (int k = 0; k < cnt; k++) {
                result[k] = arr[j].s;
                j++;
            }
            return cnt;
        }
    }
    
    return 0;
}

int main() {

    scanf("%d%d%d", &N, &L, &U);
    for (int i = 0; i < N; i++) {
        scanf("%d", &W[i]);
    }
    int n = find_subset(L, U, W, N, ans);
    printf("%d\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");
    
    return 0;
}
