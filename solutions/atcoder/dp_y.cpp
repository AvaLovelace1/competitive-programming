/*
 * Solution to Grid 2 by Ava Pun
 * Key concepts: dynamic programming, mathematics, combinatorics
 */

#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int W, H, N;
pair<int, int> block[3001];
long long fact[200001];
long long dp[3001];

long long modpow(long long a, long long b) {
    if (b == 0) return 1;
    long long ans = modpow(a * a % MOD, b / 2);
    if (b % 2 != 0) ans = (ans * a) % MOD;
    return ans;
}

long long modinv(long long a) { return modpow(a, MOD-2); }

long long binom(long long n, long long k) {
    return fact[n] * modinv(fact[k]) % MOD * modinv(fact[n-k]) % MOD;
}

long long numPaths(int W, int H) {
    if (W <= 0 || H <= 0) return 0;
    return binom(W + H - 2, W - 1);
}

int main() {

    cin >> W >> H >> N;
    for (int i = 0; i < N; ++i) cin >> block[i].first >> block[i].second;
    block[N++] = {W, H};
    sort(block, block+N);

    fact[0] = 1;
    for (long long i = 1; i <= W+H-2; ++i) fact[i] = (fact[i-1] * i) % MOD;

    for (int i = 0; i < N; ++i) {
        dp[i] = numPaths(block[i].first, block[i].second);
        for (int j = 0; j < i; ++j) {
            long long invalid = dp[j] * numPaths(block[i].first - block[j].first + 1, block[i].second - block[j].second + 1) % MOD;
            dp[i] = (dp[i] - invalid + MOD) % MOD;
        }
    }

    cout << dp[N-1] << '\n';

}
