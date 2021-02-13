/*
 * Solution to Eight Queens by Ava Pun
 * Key concepts: implementation
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

using ll = long long int;
using pii = pair<int, int>;
using piii = pair<int, pii>;
using vi = vector<int>;
using vii = vector<pii>;
const int INF = 0x3F3F3F3F;
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const int MAX = 1e5 + 2;

char arr[8][8];

bool chDiags1(vi &posns) {
    vi diags(16);
    for (int i = 0; i < 8; ++i) {
        int j = posns[i];
        int diag = i + j;
        diags[diag]++;
    }
    for (int i : diags) {
        if (i > 1) return false;
    }
    return true;
}

bool chDiags2(vi &posns) {
    vi diags(16);
    for (int i = 0; i < 8; ++i) {
        int j = posns[i];
        int diag = i - j + 8;
        diags[diag]++;
    }
    for (int i : diags) {
        if (i > 1) return false;
    }
    return true;
}

bool check(vi &posns) {
    return chDiags1(posns) && chDiags2(posns);
}

vi posns(8);
bool done[8];

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 8; ++i) {
        posns[i] = -1;
    }

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            cin >> arr[i][j];
            if (arr[i][j] == '*') {
                if (posns[i] != -1 || done[j]) {
                    cout << "invalid" << '\n';
                    return 0;
                }
                posns[i] = j;
                done[j] = 1;
            }
        }
    }
    if (accumulate(done, done + 8, 0) != 8) {
        cout << "invalid" << '\n';
        return 0;
    }

    cout << (check(posns) ? "valid" : "invalid") << '\n';

}
