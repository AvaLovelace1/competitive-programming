/*
 Solution to ECOO '19 R1 P2 - L-Systems Go by Ava Pun
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
const int MAX = 1e7 + 5;

int R, T;
string A;
string rules[26];
ll cnt[26], tmp[26];
char S, E;

int main() {
    
    for (int test = 1; test <= 10; test++) {
        cin >> R >> T >> A;
        S = A[0], E = A[A.length() - 1];
        FILL(cnt, 0), FILL(tmp, 0);
        for (int i = 0; i < 26; i++) {
            rules[i] = (char) ('A' + i);
        }
        for (char c : A) {
            cnt[c - 'A']++;
        }
        char c;
        while (R--) {
            cin >> c;
            cin >> rules[c - 'A'];
        }
        while (T--) {
            for (int i = 0; i < 26; i++) {
                tmp[i] = cnt[i];
                cnt[i] = 0;
            }
            for (int i = 0; i < 26; i++) {
                for (char c : rules[i]) {
                    cnt[c - 'A'] += tmp[i];
                }
            }
            S = rules[S - 'A'][0];
            E = rules[E - 'A'][rules[E - 'A'].length() - 1];
        }
        cout << S << E << ' ' << accumulate(cnt, cnt + 26, 0LL) << '\n';
    }
    
    return 0;
}
