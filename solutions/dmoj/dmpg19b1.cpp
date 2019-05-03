/*
 Solution to DMPG '19 B1 - Registration by Ava Pun
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
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1e9 + 7;
const int MAX = 505;

int N;

int main() {

    scanf("%d", &N);
    int n;
    int sum = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d", &n);
        sum += n;
    }
    if (sum > 200) {
        printf("Over maximum capacity!\n");
    } else {
        printf("%d\n", 200 - sum);
    }

    return 0;
}
