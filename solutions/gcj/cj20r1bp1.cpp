/*
 Solution to Google Code Jam '20 R1B P1 - Expogo by Ava Pun
 Key concepts: mathematics, greedy algorithms
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
const int INF = 0x3F3F3F3F;
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9;
const int MAX = 1e5 + 5;
const double EPS = 1e-9;

int T;
int X, Y;

int main() {
    
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    for (int test = 1; test <= T; test++) {
        
        cin >> X >> Y;

        bool flipX = X < 0, flipY = Y < 0;
        X = abs(X), Y = abs(Y);

        string ans = "";
        while (X != 0 || Y != 0) {
            if ((X & 1) == (Y & 1)) {
                ans = "IMPOSSIBLE";
                break;
            } else if ((X == 0 && Y == 1)|| (Y == 0 && X == 1) || ((X >> 1) & 1) != ((Y >> 1) & 1)) {
                if (X & 1) {
                    X -= 1;
                    ans += 'E';
                } else {
                    Y -= 1;
                    ans += 'N';
                }               
            } else {
                if (X & 1) {
                    X += 1;
                    ans += 'W';
                } else {
                    Y += 1;
                    ans += 'S';
                }
            }
            X >>= 1, Y >>= 1;
        }

        if (ans != "IMPOSSIBLE") {
            if (flipX) {
                for (char &c : ans) {
                    if (c == 'E') {
                        c = 'W';
                    } else if (c == 'W') {
                        c = 'E';
                    }
                }
            }
            if (flipY) {
                for (char &c : ans) {
                    if (c == 'N') {
                        c = 'S';
                    } else if (c == 'S') {
                        c = 'N';
                    }
                }
            }
        }

        cout << "Case #" << test << ": " << ans << "\n";
    }
    
    return 0;
}
