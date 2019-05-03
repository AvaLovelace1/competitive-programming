/*
 Solution to DMPG '19 B6 - Oddity by Ava Pun
 Key concepts: ad hoc, mathematics
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
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1e9 + 7;
const int MAX = 505;

int N, K;
int arr[MAX];
bool odd[MAX];

int main() {

    scanf("%d%d", &N, &K);
    for (int i = 1; i <= K; i++) {
        scanf("%d", &arr[i]);
    }   

    int n = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= K; j++) {
            scanf("%d", &n);
            odd[i] ^= n;
        }
    }

    int sum = accumulate(odd + 1, odd + N + 1, 0);
    sort(arr + 1, arr + K + 1);
    if (sum == N) {
        printf("%d\n", arr[1] + arr[2]);
    } else if (sum == 0) {
        printf("%d\n", arr[1]);
    } else {
        printf("-1\n");
    }

    return 0;
}
