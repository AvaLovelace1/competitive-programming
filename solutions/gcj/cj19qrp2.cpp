/*
 Solution to Google Code Jam '19 QR P2 - You Can Go Your Own Way by Ava Pun
 Key concepts: ad hoc
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
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;

int T, N;
string S;

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    for (int testN = 1; testN <= T; testN++) {
        cin >> N >> S;
        string ans = "";
        for (char &c : S) {
            if (c == 'S') {
                ans += 'E';
            } else {
                ans += 'S';
            }
        }
        cout << "Case #" << testN << ": " << ans << "\n";
    }
    
    return 0;
}
