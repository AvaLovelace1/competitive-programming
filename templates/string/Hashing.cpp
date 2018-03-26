/*
 ~ Hashing ~
 
 O(1) comparison of strings, with a very small chance of giving a false positive.
 
 Time complexity:
 Preprocessing - O(N)
 Query - O(1)
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;
const int BASE = 137;

int N, Q;
string S;
ll hsh[MAX], power[MAX];

void initPow() {
    power[0] = 1;
    for (int i = 1; i <= N; i++) {
        power[i] = power[i - 1] * BASE % MOD;
    }
}

void initHsh(string &S, int &N, ll hsh[]) {
    S = ' ' + S;
    hsh[0] = 0;
    for (int i = 1; i < S.length(); i++) {
        hsh[i] = (hsh[i - 1] * BASE % MOD + S[i]) % MOD;
    }
}

ll getHsh(int l, int r) {
    // assumes 1-based indexing
    return (hsh[r] - hsh[l - 1] * power[r - (l - 1)] % MOD + MOD) % MOD;
}

int main() {
    
    cin.sync_with_stdio(0);
    cin.tie();
    
    cin >> S >> Q;
    N = (int) S.length();
    initPow();
    initHsh(S, N, hsh);
    
    int a, b;
    while (Q--) {
        cin >> a >> b;
        cout << "Hash from position " << a << " to " << b << ": " << getHsh(a, b) << "\n";
    }
    
    return 0;
    
}
