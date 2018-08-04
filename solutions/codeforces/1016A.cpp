/*
 Solution to Death Note by Ava Pun
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
typedef pair<pii, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;

int N, M;

int main() {
    
    scanf("%d%d", &N, &M);
    int cnt, curr = 0, n;
    for (int i = 1; i <= N; i++) {
        cnt = 0;
        scanf("%d", &n);
        int nn = min(M - curr, n);
        curr += nn, n -= nn;
        if (curr >= M) {
            curr = 0;
            cnt++;
        }
        if (n) {
            cnt += n / M;
            curr += n % M;
        }
        printf("%d ", cnt);
    }
    printf("\n");
    
    return 0;
}
