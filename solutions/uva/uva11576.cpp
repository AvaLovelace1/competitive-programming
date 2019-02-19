/*
 Solution to 11576 - Scrolling Sign by Ava Pun
 Key concepts: hashing
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
const int MOD = 1e9 + 7;
const int MAX = 105;
const int BASE = 29;

int T, K, N;
ll power[MAX], hsh[2][MAX];
char str[MAX];

inline void genHsh(ll hsh[]) {
    for (int i = 1; i <= K; i++) {
        scanf(" %c", &str[i]);
    }
    for (int i = 1; i <= K; i++) {
        hsh[i] = (hsh[i - 1] * BASE % MOD + (str[i] - 'A' + 1)) % MOD;
    }
}

inline ll getHsh(int l, int r, ll hsh[]) {
    return (hsh[r] - hsh[l - 1] * power[r - l + 1] % MOD + MOD) % MOD;
}

inline bool check(int x, ll hsh1[], ll hsh2[]) {
    return getHsh(K - x + 1, K, hsh1) == getHsh(1, x, hsh2);
}

int main() {
    
    power[0] = 1;
    for (int i = 1; i <= 100; i++) {
        power[i] = power[i - 1] * BASE % MOD;
    }
    
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%d%d", &K, &N);
        int ans = N * K;
        genHsh(hsh[1]);
        for (int i = 2; i <= N; i++) {
            genHsh(hsh[i & 1]);
            int maxN = 0;
            for (int j = 1; j <= K; j++) {
                if (check(j, hsh[!(i & 1)], hsh[i & 1])) {
                    maxN = j;
                }
            }
            ans -= maxN;
        }
        printf("%d\n", ans);
    }
    
    return 0;
}
