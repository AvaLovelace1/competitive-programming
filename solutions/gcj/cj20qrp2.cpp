/*
 Solution to Google Code Jam '20 QR P2 - Nesting Depth by Ava Pun
 Key concepts: implementation
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
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;
const double EPS = 1e-9;

int T;
string S;

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    for (int test = 1; test <= T; test++) {
        cin >> S;
        string ans = "";
        int dep = 0;
        for (int i = 0; i < S.length(); i++) {
            int digit = S[i] - '0';
            while (dep < digit) {
                ans += '(';
                dep++;
            }
            while (dep > digit) {
                ans += ')';
                dep--;
            }
            ans += S[i];
        }
        while (dep--) {
            ans += ')';
        }
        cout << "Case #" << test << ": " << ans << "\n";
    }

    return 0;
}
