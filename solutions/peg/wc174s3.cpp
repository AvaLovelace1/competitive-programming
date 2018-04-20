/*
 Solution to WC17 #4 - Guardians of the Cash by Ava Pun
 Key concepts: simulation, segment tree
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
const int MAX = 1005;

int N;
int arr[MAX][MAX], arr1[MAX][MAX];
int rtree[MAX][2 * MAX], ctree[MAX][2 * MAX];

void build(int tree[], int arr[]) {
    for (int i = 1; i <= N; i++) {
        tree[i + N - 1] = arr[i];
    }
    for (int i = N - 1; i > 0; i--) {
        tree[i] = max(tree[i << 1], tree[i << 1 | 1]);
    }
}

void update(int pos, int x, int tree[]) {
    tree[pos] = x;
    for (int i = pos >> 1; i > 0; i >>= 1) {
        tree[i] = max(tree[i << 1], tree[i << 1 | 1]);
    }
}

int main() {
    
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            arr1[i][j] = arr[j][i];
        }
    }
    for (int i = 1; i <= N; i++) {
        build(rtree[i], arr[i]);
        build(ctree[i], arr1[i]);
    }
    
    bool done = false;
    ll ans = 0;
    while (!done) {
        done = true;
        for (int i = 1; i <= N; i++) {
            if (rtree[i][1] != ctree[i][1]) {
                done = false;
                int *ptr = rtree[i][1] > ctree[i][1] ? rtree[i] : ctree[i];
                int minN = min(rtree[i][1], ctree[i][1]);
                for (int j = N; j < 2 * N; j++) {
                    if (ptr[j] > minN) {
                        ans += ptr[j] - minN;
                        update(j, minN, ptr);                        
                        if (ptr == rtree[i]) {
                            update(i + N - 1, minN, ctree[j - N + 1]);
                        } else {
                            update(i + N - 1, minN, rtree[j - N + 1]);
                        }
                    }
                }
            }
        }
    }
    printf("%lld\n", ans);
    
    return 0;
}
