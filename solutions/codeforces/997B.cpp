/*
 Solution to Roman Digits by Ava Pun
 Key concepts: brute force, ad hoc
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
const int MOD = 1e9 + 7;
const int MAX = 5e4 + 5;

int N;
bool bad[10][50];

inline int sum(int i, int j) {
    return 4 * i + 9 * j;
}

int main() {
    
    scanf("%d", &N);
    
    int x = min(8, N), y = min(48, N);
    for (int i = 0; i <= x; i++) {
        for (int j = 0; j <= y; j++) {
            for (int k = 0; k <= x; k++) {
                for (int l = 0; l <= y; l++) {
                    if (i + j <= N && k + l <= N && !(i == k && j == l)) {
                        int a = sum(i, j), b = sum(k, l);
                        if (a > b && (a - b) % 49 == 0) {
                            bad[i][j] = 1;
                        }
                    }
                }
            }
        }
    }
    
    ll ans = 0;
    for (int i = 0; i <= x; i++) {
        for (int j = 0; j <= y; j++) {
            if (i + j <= N && !bad[i][j]) {
                ans += N - i - j + 1;
            }
        }
    }
    printf("%lld\n", ans);
    
    return 0;
}
