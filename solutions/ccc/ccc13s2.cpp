/*
 Solution to CCC '13 S2 - Bridge Transport by Ava Pun
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
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3f3f3f3f;
const int MAX = 1e5 + 5;

int W, N;
int arr[MAX];

int main() {

    scanf("%d%d", &W, &N);
    ll tot = 0;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
        if (i > 4) {
            tot -= arr[i - 4];
        }
        tot += arr[i];
        if (tot > W) {
            printf("%d\n", i - 1);
            return 0;
        }
    }
    printf("%d\n", N);

    return 0;
}
