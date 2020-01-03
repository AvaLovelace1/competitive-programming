/*
 Solution to Strange Device by Ava Pun
 Key concepts: interactive
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef double lf;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 998244353;
const int MAX = 1e6 + 5;
const int MAXL = 17;

int N, K;
int arr[505], ans[505];

inline void quer(int skip) {
    printf("?");
    for (int i = 1; i <= K + 1; i++) {
        if (i != skip) {
            printf(" %d", i);
        }
    }
    printf("\n");
    fflush(stdout);
    int pos, a;
    scanf("%d", &pos);
    if (pos == -1) {
        exit(0);
    } else {
        scanf("%d", &a);
        ans[skip] = a;
    }
}

inline void answer(int x) {
    printf("! %d\n", x);
    fflush(stdout);
}

int main() {

    scanf("%d%d", &N, &K);
    int a = -1, b = -1;
    for (int i = 1; i <= K + 1; i++) {
        quer(i);
        if (a == -1) {
            a = ans[i];
        } else if (ans[i] != a) {
            b = ans[i];
        }
    }
    if (a < b) {
        swap(a, b);
    }
    int aCnt = 0;
    for (int i = 1; i <= K + 1; i++) {
        if (ans[i] == a) {
            aCnt++;
        }
    }
    answer(aCnt);

    return 0;
}
