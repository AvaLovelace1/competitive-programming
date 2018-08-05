/*
 Solution to AcCepted by Ava Pun
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
typedef pair<pii, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;

string S;

int main() {
    
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> S;
    
    int cnt = 0, upper = 0, pos = 0;
    for (int i = 0; i < S.length(); i++) {
        if (S[i] == 'C') {
            cnt++;
            pos = i;
        }
        if (isupper(S[i])) {
            upper++;
        }
    }
    cout << (cnt == 1 && pos >= 2 && pos <= S.length() - 2 && upper == 2 && S[0] == 'A' ? "AC\n" : "WA\n");
    
    return 0;
}
