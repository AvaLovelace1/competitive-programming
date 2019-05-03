/*
 Solution to Back to School '16: Contest Practice by Ava Pun
 Key concepts: nD prefix sum array
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
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9;
const int MAX = 5e4 + 5;

int P, Q, N, X, QP;
int pref[200005];

inline int readInput() {
    int n;
    int pos = 0;
    for (int j = 0; j < P; j++) {
        pos *= Q;
        scanf("%d", &n);
        n = Q - n - 1;
        pos += n;
    }
    return pos;
}

int main() {

    scanf("%d%d%d", &P, &Q, &N);
    QP = (int) pow(Q, P);
    for (int i = 0; i < N; i++) {
        pref[readInput()]++;
    }

    int base = 1;
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < QP; j++) {
            if (j / base % Q > 0) {
                pref[j] += pref[j - base];
            }
        }
        base *= Q;
    }

    scanf("%d", &X);
    for (int i = 0; i < X; i++) {
        printf("%d\n", pref[readInput()]);
    }

    return 0;
}
