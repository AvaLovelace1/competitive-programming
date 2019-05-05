/*
 Solution to CCC '16 S5 - Circle of Life by Ava Pun
 Key concepts: mathematics, simulation
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
const int MAX = 1e5 + 5;

int N;
ll T;
bool arr[2][MAX];

int main() {

    scanf("%d%lld", &N, &T);
    char c;
    for (int i = 0; i < N; i++) {
        scanf(" %c", &c);
        arr[0][i] = c == '1';
    }

    bool cur = 0;
    for (int i = 50; i >= 0; i--) {
        if (T - (1LL << i) >= 0) {
            T -= 1LL << i;
            cur = !cur;
            for (int j = 0; j < N; j++) {
                arr[cur][j] = arr[!cur][(j - (1LL << i) % N + N) % N] ^ arr[!cur][(j + (1LL << i)) % N];
            }
        }
    }

    for (int i = 0; i < N; i++) {
        printf("%d", arr[cur][i]);
    }
    printf("\n");

    return 0;
}
