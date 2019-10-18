/*
 Solution to Greatest Greatest Common Divisor by Ava Pun
 Key concepts: implementation, math, brute force
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<ll, ll> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;
const double EPS = 1e-9;

int N;
int arr[MAX], cnt[1000005];

int main() {

    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
        for (int j = 1; j * j <= arr[i]; j++) {
            if (arr[i] % j == 0) {
                cnt[j]++;
                if (arr[i] / j != j) {
                    cnt[arr[i] / j]++;
                }
            }
        }
    }
    for (int i = 1000000; i >= 1; i--) {
        if (cnt[i] >= 2) {
            printf("%d\n", i);
            break;
        }
    }

    return 0;
}
