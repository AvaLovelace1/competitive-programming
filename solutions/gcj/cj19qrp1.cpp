/*
 Solution to Google Code Jam '19 QR P1 - Foregone Solution by Ava Pun
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
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;

int T;
string N;

int main() {

    cin >> T;
    for (int testN = 1; testN <= T; testN++) {
        cin >> N;
        string ans = "";
        for (char &c : N) {
            if (c == '4') {
                c = '3';
                ans += '1';
            } else if (ans != "") {
                ans += '0';
            }
        }
        cout << "Case #" << testN << ": " << N << " " << ans << "\n";
    }
    
    return 0;
}
