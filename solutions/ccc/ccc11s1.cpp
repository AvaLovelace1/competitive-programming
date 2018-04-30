/*
 Solution to CCC '11 S1 - English or French? by Ava Pun
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
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 505;

int N;
int cnt[2];
string S;

int main() {
    
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    cin.ignore();
    while (N--) {
        getline(cin, S);
        for (char c : S) {
            if (c == 't' || c == 'T') {
                cnt[0]++;
            } else if (c == 's' || c == 'S') {
                cnt[1]++;
            }
        }
    }
    cout << (cnt[0] > cnt[1] ? "English\n" : "French\n");
    
    return 0;
}
