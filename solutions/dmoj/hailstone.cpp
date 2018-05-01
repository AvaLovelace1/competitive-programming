/*
 Solution to Hailstone Numbers by Ava Pun
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
const int MAX = 1e6 + 5;

ll N;

int main() {

    scanf("%lld", &N);
    int ans = 0;
    while (N != 1) {
        if (N % 2 == 0) {
            N /= 2;
        } else {
            N = N * 3 + 1;
        }
        ans++;
    }
    printf("%d\n", ans);
    
    return 0;
}
