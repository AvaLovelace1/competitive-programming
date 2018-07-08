/*
 Solution to DMOPC '17 Contest 4 P5 - Revised IOI by Ava Pun
 Key concepts: brute force
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
const int MAX = 5005;

int N;
string arr[4];
int cnt[16], scores[4];

int main() {
    
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for (int i = 0; i < 4; i++) {
        cin >> arr[i];
    }
    
    for (int i = 0; i < N; i++) {
        int val = 0;
        for (int j = 0; j < 4; j++) {
            val += (arr[j][i] == 'T') << j;
        }
        cnt[val]++;
    }
    
    ll best = -1;
    int ans = -1;
    for (int m = 0; m < (1 << 16); m++) {
        for (int i = 0; i < 4; i++) {
            scores[i] = 0;
        }
        for (int i = 0; i < 16; i++) {
            int t = m & (1 << i);
            for (int j = 0; j < 4; j++) {
                if (i & (1 << j)) {
                    scores[j] += t ? cnt[i] : -cnt[i];
                } else {
                    scores[j] += t ? -cnt[i] : cnt[i];
                }
            }
        }
        ll curr = 0;
        for (int i = 0; i < 4; i++) {
            curr += (ll) scores[i] * scores[i];
        }
        if (curr > best) {
            best = curr;
            ans = m;
        }
    }
    
    for (int i = 0; i < N; i++) {
        int val = 0;
        for (int j = 0; j < 4; j++) {
            val += (arr[j][i] == 'T') << j;
        }
        cout << (ans & (1 << val) ? 'T' : 'F');
    }
    cout << '\n';
    
    return 0;
}
