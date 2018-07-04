/*
 Solution to Convert to Ones by Ava Pun
 Key concepts: greedy algorithms
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
const int MAX = 5e4 + 5;

int N, X, Y;
string S;

int main() {
    
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> X >> Y >> S;
    S = S + "1";
    
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == '0' && S[i + 1] == '1') {
            cnt++;
        }
    }
    printf("%lld\n", cnt == 0 ? 0 : (ll) (cnt - 1) * min(X, Y) + Y);
    
    return 0;
}
