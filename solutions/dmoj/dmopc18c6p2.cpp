/*
 Solution to DMOPC '18 Contest 6 P2 - Enantiomers by Ava Pun
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
const int MAX = 1e5 + 5;

const int SEQS[12][4] = {
    {0, 1, 2, 3}, {0, 2, 3, 1}, {0, 3, 1, 2},
    {1, 0, 3, 2}, {1, 3, 2, 0}, {1, 2, 0, 3},
    {2, 0, 1, 3}, {2, 1, 3, 0}, {2, 3, 0, 1},
    {3, 0, 2, 1}, {3, 2, 1, 0}, {3, 1, 0, 2},
};
string arr[2][4], sorted[2][4];

int main() {
    
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> arr[i][j];
            sorted[i][j] = arr[i][j];
            assert(arr[i][j].length() <= 5);
        }
        sort(sorted[i], sorted[i] + 4);
    }
    
    for (int i = 0; i < 4; i++) {
        if (sorted[0][i] != sorted[1][i] || (i > 0 && sorted[0][i - 1] == sorted[0][i])) {
            cout << "NO\n";
            return 0;
        }
    }
    
    for (int i = 0; i < 12; i++) {
        bool match = 1;
        for (int j = 0; j < 4; j++) {
            if (arr[0][SEQS[i][j]] != arr[1][j]) {
                match = 0;
                break;
            }
        }
        if (match) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    
    return 0;
}
