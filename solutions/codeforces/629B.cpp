/*
 Solution to Far Relative’s Problem by Ava Pun
 Key concepts: implementation, brute force
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
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;
const double EPS = 1e-9;

int N;
int cnt[2][400];

int main() {

    scanf("%d", &N);
    char c;
    int a, b;
    for (int i = 1; i <= N; i++) {
        scanf(" %c%d%d", &c, &a, &b);
        int g = c == 'F';
        for (int i = a; i <= b; i++) {
            cnt[g][i]++;
        }
    }
    int ans = 0;
    for (int i = 1; i <= 366; i++) {
        ans = max(ans, 2 * min(cnt[0][i], cnt[1][i]));
    }
    printf("%d\n", ans);

    return 0;
}
