/*
 Solution to MNYC '17: Hurontario by Ava Pun
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
const int MAX = 1e6 + 5;
const int BASE = 31;

int N1, N2;
string S1, S2;
ll power[MAX], hsh1[MAX], hsh2[MAX];

void initHsh(string &S, int &N, ll hsh[]) {
    N = (int) S.length();
    S = ' ' + S;
    hsh[0] = 0;
    for (int i = 1; i <= N; i++) {
        hsh[i] = (hsh[i - 1] * BASE % MOD + (S[i] - 'A' + 1)) % MOD;
    }
}

ll getHsh(int l, int r, ll hsh[]) {
    return (hsh[r] - hsh[l - 1] * power[r - (l - 1)] % MOD + MOD) % MOD;
}

bool check(int n) {
    return getHsh(N1 - n + 1, N1, hsh1) == getHsh(1, 1 + n - 1, hsh2);
}

int main() {
    
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> S1 >> S2;
    
    power[0] = 1;
    for (int i = 1; i <= max(S1.length(), S2.length()); i++) {
        power[i] = power[i - 1] * BASE % MOD;
    }
    initHsh(S1, N1, hsh1);
    initHsh(S2, N2, hsh2);
    
    int ans = 0;
    for (int i = 1; i <= min(N1, N2); i++) {
        if (getHsh(N1 - i + 1, N1, hsh1) == getHsh(1, 1 + i - 1, hsh2)) {
            ans = i;
        }
    }
    
    cout << S1.substr(1, string::npos) << S2.substr(ans + 1, string::npos) << "\n";
    
    return 0;
}
