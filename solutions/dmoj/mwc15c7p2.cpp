/*
 Solution to MWC '15 #7 P2: Thief in the Night by Ava Pun
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
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 1e4 + 5;

int F, N, Q;
int arr[6][MAX];

int query(int i, int l, int r) {
    return arr[i][r] - arr[i][l - 1];
}

int main() {

    scanf("%d%d", &F, &N);
    for (int i = 1; i <= F; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &arr[i][j]);
            arr[i][j] += arr[i][j - 1];
        }
    }
    scanf("%d", &Q);
    int a, b, c;
    while (Q--) {
        scanf("%d%d%d", &a, &b, &c);
        printf("%d\n", query(c, a, b));
    }
    
    return 0;
}
