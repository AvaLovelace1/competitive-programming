/*
 * Solution to Grid 1.5 by Ava Pun
 * Key concepts: dynamic programming, mathematics, combinatorics
 */

#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int W, H, X;
pair<int, int> block[2];
long long fact[2000001];

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

long long solve1(int W, int H, pair<int, int> b) {
    return numPaths(b.first, b.second)
        * numPaths(W - b.first + 1, H - b.second + 1) % MOD;
}

long long solve2(int W, int H, pair<int, int> block[]) {
    long long invalid0 = solve1(W, H, block[0]);
    long long invalid1 = solve1(W, H, block[1]);
    long long invalid2 = numPaths(block[0].first, block[0].second)
        * numPaths(block[1].first - block[0].first + 1, block[1].second - block[0].second + 1) % MOD
        * numPaths(W - block[1].first + 1, H - block[1].second + 1) % MOD;
    return ((invalid0 + invalid1) % MOD - invalid2 + MOD) % MOD;
}

long long solve(int W, int H, int X) {
    long long invalid;
    if (X == 0) invalid = 0;
    else if (X == 1) invalid = solve1(W, H, block[0]);
    else invalid = solve2(W, H, block);
    return (numPaths(W, H) - invalid + MOD) % MOD;
}

int main() {

    cin >> W >> H >> X;
    for (int i = 0; i < X; ++i)
        cin >> block[i].first >> block[i].second;
    sort(block, block+X);

    fact[0] = 1;
    for (long long i = 1; i <= W+H-2; ++i) fact[i] = (fact[i-1] * i) % MOD;

    cout << solve(W, H, X) << '\n';

}
