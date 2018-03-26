/*
 Solution to ECOO '16 R2 P1 - Palindrome Panic by Ava Pun
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

int N;
string S, SR;
ll power[MAX], hsh[MAX], hshRev[MAX];

void init(string str, ll hsh[]) {
    str = ' ' + str;
    hsh[0] = 0;
    for (int i = 1; i <= N; i++) {
        hsh[i] = (hsh[i - 1] * BASE % MOD + (str[i] - 'a' + 1)) % MOD;
    }
}

ll getHsh(int l, int r, ll hsh[]) {
    if (l > r) {
        return 0;
    }
    return (hsh[r] - hsh[l - 1] * power[r - (l - 1)] % MOD + MOD) % MOD;
}

int main() {
    
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    power[0] = 1;
    for (int i = 1; i <= MAX - 5; i++) {
        power[i] = power[i - 1] * BASE % MOD;
    }
    
    for (int test = 1; test <= 10; test++) {
        
        cin >> S;
        N = (int) S.length();
        SR = S;
        reverse(SR.begin(), SR.end());
        init(S, hsh);
        init(SR, hshRev);
        
        int ans = INF, len;
        for (int i = 1; i <= N; i++) {
            len = min(i, N - i + 1);
            if (getHsh(i - len + 1, i, hsh) == getHsh(N - (i + len - 1) + 1, N - i + 1, hshRev)) {
                ans = min(ans, N - (2 * len - 1));
            }
            if (i != N) {
                len = min(i, N - i);
                if (getHsh(i - len + 1, i, hsh) == getHsh(N - (i + len) + 1, N - (i + 1) + 1, hshRev)) {
                    ans = min(ans, N - 2 * len);
                }
            }
        }
        cout << ans << "\n";
        
    }
    
    return 0;
}
