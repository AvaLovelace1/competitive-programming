/*
 Solution to Plasticine zebra by Ava Pun
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
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 998244353;
const int MAX = 150000 + 5;

int N;
string S;

int main() {
    
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> S;
    S += S;
    N = (int) S.length();
    int maxN = 1;
    int len = 1;
    for (int i = 1; i < N; i++) {
        maxN = max(maxN, len);
        if (S[i] != S[i - 1]) {
            len++;
        } else {
            len = 1;
        }
    }
    cout << min(maxN, N / 2) << "\n";

    return 0;
}
