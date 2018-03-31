/*
 Solution to Dog Girls by Ava Pun
 Key concepts: hashing
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
const int MAX = 5005;
const int BASE = 31;

int N;
string S;
ll hsh[MAX], power[MAX];
unordered_set<ll> ss;

ll getHsh(int l, int r) {
    return (hsh[r] - hsh[l - 1] * power[r - (l - 1)] % MOD + MOD) % MOD;
}

int main() {
    
    cin >> S;
    N = (int) S.length();
    S = ' ' + S;
    
    power[0] = 1;
    for (int i = 1; i <= N; i++) {
        power[i] = power[i - 1] * BASE % MOD;
    }
    hsh[0] = 0;
    for (int i = 1; i <= N; i++) {
        hsh[i] = (hsh[i - 1] * BASE % MOD + (S[i] - 'a' + 1)) % MOD;
    }
    
    ll prev = 0;
    int cnt = 0, idx = 0;
    for (int k = 1; k <= N / 2; k++) {
        for (int j = 1; j < 1 + k; j++) {
            prev = 0, cnt = 0, idx = 0;
            for (int i = j; i + k - 1 <= N; i += k) {
                ll h = getHsh(i, i + k - 1);
                if (h != prev) {
                    idx = i;
                    cnt = 1;
                    prev = h;
                } else {
                    cnt++;
                }
                if (cnt > 1) {
                    ss.insert(getHsh(idx, i + k - 1));
                }
            }
        }
    }
    
    cout << ss.size() << "\n";
    
    return 0;
}
