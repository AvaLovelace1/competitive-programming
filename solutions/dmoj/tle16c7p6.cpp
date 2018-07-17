/*
 Solution to TLE '16 Contest 7 P6 - Everyone Hates Reading by Ava Pun
 Key concepts: trie
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
const int MAX = 1e5 + 5;

int N, M;
int trie[MAX][26];
vi idx[MAX], idxEnd[MAX];
int cnt = 1;

inline void insert(string str, int x) {
    int n = 0;
    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        if (trie[n][c - 'a'] == 0) {
            trie[n][c - 'a'] = cnt++;
        }
        n = trie[n][c - 'a'];
        if (i != str.length() - 1) {
            idx[n].pb(x);
        } else {
            idxEnd[n].pb(x);
        }
    }
}

inline int query(string str, int l, int r) {
    int n = 0, ans = 0;
    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        if (trie[n][c - 'a'] == 0) {
            break;
        }
        n = trie[n][c - 'a'];
        ans += (int) (upper_bound(idxEnd[n].begin(), idxEnd[n].end(), r) - lower_bound(idxEnd[n].begin(), idxEnd[n].end(), l));
        if (i == str.length() - 1) {
            ans += (int) (upper_bound(idx[n].begin(), idx[n].end(), r) - lower_bound(idx[n].begin(), idx[n].end(), l));
        }
    }
    return ans;
}

int main() {
    
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;
    
    string str;
    for (int i = 1; i <= N; i++) {
        cin >> str;
        insert(str, i);
    }
    
    int l, r;
    while (M--) {
        cin >> str >> l >> r;
        cout << query(str, l, r) << '\n';
    }
    
    return 0;
}
