/*
 Solution to Minimum Ternary String by Ava Pun
 Key concepts: greedy algorithms, implementation
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
const int MAX = 1000 + 5;

string S;

int main() {
    
    cin >> S;
    int cnt = 0;
    for (char c : S) {
        if (c == '1') {
            cnt++;
        }
    }
    bool done = 0;
    for (char c : S) {
        if (c == '2' && !done) {
            while (cnt--) {
                cout << '1';
            }
            done = 1;
        }
        if (c != '1') {
            cout << c;
        }
    }
    if (!done) {
        while (cnt--) {
            cout << '1';
        }
    }
    cout << '\n';
    
    return 0;
}
