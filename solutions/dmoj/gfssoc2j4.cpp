/*
 Solution to Marathon by Ava Pun
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
const int MAX = 5e5 + 5;

int N, Q;
int arr[MAX];

int query(int l, int r) {
    return arr[r] - arr[l - 1];
}

int main() {

    scanf("%d%d", &N, &Q);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
        arr[i] += arr[i - 1];
    }
    int a, b;
    while (Q--) {
        scanf("%d%d", &a, &b);
        printf("%d\n", query(1, N) - query(a, b));
    }
    
    return 0;
}
