/*
 Solution to WC17 #3 - GleamingProudChickenFunRun by Ava Pun
 Key concepts: greedy algorithms, monoqueue
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
const int MAX = 3e5 + 5;

int N, N1;
pii arr[MAX], arr1[MAX];

inline bool comp(pii a, pii b) {
    return a.s == b.s ? a > b : a.s < b.s;
}

int main() {
    
    scanf("%d\n", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d%d", &arr[i].f, &arr[i].s);
    }
    sort(arr + 1, arr + N + 1, comp);
    
    for (int i = 1; i <= N; i++) {
        while (N1 > 0 && arr1[N1].f >= arr[i].f) {
            N1--;
        }
        N1++;
        arr1[N1] = arr[i];
    }
    
    int ans = 0;
    int j = 1;
    for (int i = 1; i <= N; i++) {
        while (j <= N1 - 1 && arr1[j + 1].f < arr[i].s) {
            j++;
        }
        ans++;
        while (i <= N - 1 && arr[i + 1].f < arr1[j].s) {
            i++;
        }
    }
    printf("%d\n", ans);
    
    return 0;
}
