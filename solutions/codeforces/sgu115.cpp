/*
 Solution to Calendar by Ava Pun
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
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;
const double EPS = 1e-9;

int N, M;
int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {

    scanf("%d%d", &N, &M);
    if (M > 12 || N > days[M]) {
        printf("Impossible\n");
    } else {
        int ans = 0;
        for (int i = 1; i < M; i++) {
            ans += days[i];
        }
        ans += N - 1;
        ans = (ans % 7) + 1;
        printf("%d\n", ans);
    }

    return 0;
}
