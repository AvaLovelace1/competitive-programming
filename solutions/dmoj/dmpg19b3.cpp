/*
 Solution to DMPG '19 B3 - Contact by Ava Pun
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
const int MAX = 505;

string S;
int K;

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> S >> K;
    int cnt = 0;
    for (int i = 0; i < S.length(); i++) {
        if (S[i] == 'R') {
            cnt = 0;
        } else {
            cnt++;
        }
        if (cnt >= K) {
            cout << "Spamming\n";
            return 0;
        }
    }
    cout << "All good\n";

    return 0;
}
