/*
 Solution to Annoying Present by Ava Pun
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
const int MAX = 1e5 + 5;

int N, M;
int arr[MAX];

int main() {
    
    scanf("%d%d", &N, &M);
    int x, d;
    ll maxN = 0, minN = 0, ans = 0;
    for (int i = 1; i <= N; i++) {
        maxN += abs(i - 1);
        minN += abs(i - (N + 1) / 2);
    }
    for (int i = 1; i <= M; i++) {
        scanf("%d%d", &x, &d);
        ans += x * N;
        if (d < 0) {
            ans += minN * d;
        } else {
            ans += maxN * d;
        }
    }
    printf("%.15lf\n", (double) ans / N);
    
    return 0;
}
