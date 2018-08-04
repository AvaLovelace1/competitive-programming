/*
 Solution to Segment Occurrences by Ava Pun
 Key concepts: prefix sum array
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
const int MAX = 1005 + 5;

int N, M, Q;
string S, T;
int pref[MAX];

int main() {
    
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M >> Q >> S >> T;
    for (int i = 0; i < N; i++) {
        int j = i;
        bool good = 1;
        for (char c : T) {
            if (j >= N || S[j] != c) {
                good = 0;
                break;
            }
            j++;
        }
        if (good) {
            pref[i + 1] = 1;
        }
        pref[i + 1] += pref[i];
    }
    
    int l, r;
    while (Q--) {
        cin >> l >> r;
        if (r - l + 1 < M) {
            cout << "0\n";
        } else {
            cout << pref[r - M + 1] - pref[l - 1] << '\n';
        }
    }
    
    return 0;
}
