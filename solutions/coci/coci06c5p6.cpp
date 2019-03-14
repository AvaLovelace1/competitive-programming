/*
 Solution to COCI '06 Contest 5 #6 Dvaput by Ava Pun
 Key concepts: hashing, binary search
 */
 
#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;
const int BASE = 29;

int N;
char S[MAX];
ll power[MAX], hsh[MAX];
unordered_map<ll, int> ss;

inline ll getHsh(int l, int r) {
    return (hsh[r] - hsh[l - 1] * power[r - l + 1] % MOD + MOD) % MOD;
}

inline bool verify(int a, int b, int n) {
    for (int i = 0; i < n; i++) {
        if (S[a + i] != S[b + i]) {
            return 0;
        }
    }
    return 1;
}

inline bool check(int n) {
    ss.clear();
    for (int i = 1; i + n - 1 <= N; i++) {
        ll h = getHsh(i, i + n - 1);
        if (ss.find(h) != ss.end() && verify(i, ss[h], n)) {
            return 1;
        } else {
            ss[h] = i;
        }
    }
    return 0;
}

int main() {
    
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf(" %c", &S[i]);
    }
    
    power[0] = 1;
    for (int i = 1; i <= N; i++) {
        power[i] = power[i - 1] * BASE % MOD;
    }
    for (int i = 1; i <= N; i++) {
        hsh[i] = (hsh[i - 1] * BASE % MOD + (S[i] - 'a' + 1)) % MOD;
    }
    
    int lo = 1, hi = N + 1, mid;
    while (lo < hi) {
        mid = (lo + hi) / 2;
        if (!check(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    printf("%d\n", lo - 1);
    
    return 0;
}
