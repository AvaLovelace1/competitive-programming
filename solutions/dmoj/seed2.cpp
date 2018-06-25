/*
 Solution to Uneven Sand by Ava Pun
 Key concepts: binary search
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
const int MAX = 1e6 + 5;

int main() {
    
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    ll lo = 1, hi = 2e9;
    string S = "";
    while (S != "OK") {
        ll mid = (lo + hi) / 2;
        cout << mid << endl;
        cin >> S;
        if (S == "SINKS") {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    
    return 0;
}
