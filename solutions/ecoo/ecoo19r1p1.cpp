/*
 Solution to ECOO '19 R1 P1 - Free Shirts by Ava Pun
 Key concepts: implementation
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
const int MAX = 1e7 + 5;

int N, N1, M, D;
int arr[1005];

int main() {
    
    for (int test = 1; test <= 10; test++) {
        scanf("%d%d%d", &N, &M, &D);
        N1 = 0;
        FILL(arr, 0);
        int n;
        while (M--) {
            scanf("%d", &n);
            arr[n]++;
        }
        int ans = 0;
        for (int i = 1; i <= D; i++) {
            if (N == 0) {
                ans++;
                N = N1, N1 = 0;
            }
            N += arr[i];
            N--, N1++;
        }
        printf("%d\n", ans);
    }
    
    return 0;
}
