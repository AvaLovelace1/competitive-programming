/*
 Solution to IOI '16 P5 - Unscrambling a Messy Bug by Ava Pun
 Key concepts: divide and conquer
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

int N;
int* ans;

void insert(int l, int r) {
    if (l >= r) {
        return;
    }
    string str(N, '1');
    int m = (l + r) / 2;
    for (int i = l; i <= r; i++) {
        str[i] = '0';
    }
    for (int i = l; i <= m; i++) {
        if (i != l) {
            str[i - 1] = '0';
        }
        str[i] = '1';
        add_element(str);
    }
    insert(l, m), insert(m + 1, r);
}

void solve(int l, int r, vi v) {
    
    if (l >= r) {
        ans[v[0]] = l;
        return;
    }
    int m = (l + r) / 2;
    string str(N, '1');
    vi v1, v2;
    for (int i : v) {
        str[i] = '0';
    }

    for (int i = 0; i < v.size(); i++) {
        if (i != 0) {
            str[v[i - 1]] = '0';
        }
        str[v[i]] = '1';
        if (check_element(str)) {
            v1.pb(v[i]);
        } else {
            v2.pb(v[i]);
        }
    }
    solve(l, m, v1), solve(m + 1, r, v2);
}

int* restore_permutation(int n, int w, int r) {
    N = n;
    ans = (int*) malloc(sizeof(int) * N);
    insert(0, N - 1);
    compile_set();
    vi v(N);
    for (int i = 0; i < N; i++) {
        v[i] = i;
    }
    solve(0, N - 1, v);
    return ans;
}
