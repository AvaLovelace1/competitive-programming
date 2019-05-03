/*
 Solution to DMOPC '18 Contest 5 P0 - A Digital Art Problem by Ava Pun
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
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

string T;
double arr[2][3];

int main() {
    
    cin >> T;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> arr[i][j];
        }
    }
    
    cout << fixed << setprecision(6);
    
    if (T == "Multiply") {
        for (int i = 0; i < 3; i++) {
            cout << arr[0][i] * arr[1][i];
            cout << (i == 2 ? "\n" : " ");
        }
    } else if (T == "Screen") {
        for (int i = 0; i < 3; i++) {
            cout << 1 - (1 - arr[0][i]) * (1 - arr[1][i]);
            cout << (i == 2 ? "\n" : " ");
        }
    } else if (T == "Overlay") {
        for (int i = 0; i < 3; i++) {
            if (arr[0][i] < 0.5) {
                cout << 2 * arr[0][i] * arr[1][i];
                cout << (i == 2 ? "\n" : " ");
            } else {
                cout << 1 - 2 * (1 - arr[0][i]) * (1 - arr[1][i]);
                cout << (i == 2 ? "\n" : " ");
            }
        }
    }
    
    return 0;
}
