/*
 Solution to Preparing Problem by Ava Pun
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

int N, T1, T2;

int main() {

    scanf("%d%d%d", &N, &T1, &T2);
    int t1 = T1, t2 = T2;
    int n = 0;
    while (n < N) {
        n += 1 + (t1 == t2);
        if (n >= N) {
            printf("%d %d\n", n + !(t1 == t2), max(t1, t2));
            break;
        }
        if (t1 < t2) {
            t1 += T1;
        } else if (t2 < t1) {
            t2 += T2;
        } else {
            t1 += T1, t2 += T2;
        }
    }

    return 0;
}
