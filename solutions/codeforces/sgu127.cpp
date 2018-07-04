/*
 Solution to Telephone directory by Ava Pun
 Key concepts: implementation, simple math
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

int K, N;
int cnt[10];

int main() {
    
    scanf("%d%d", &K, &N);
    int n;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &n);
        cnt[n / 1000]++;
    }
    int ans = 2;
    for (int i = 0; i <= 9; i++) {
        ans += ceil((double) cnt[i] / K);
    }
    printf("%d\n", ans);

    return 0;
}
