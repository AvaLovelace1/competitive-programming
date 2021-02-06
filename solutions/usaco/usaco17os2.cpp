/*
 * Solution to USACO '17 Open S2 - Bovine Genomics by Ava Pun
 * Key concepts: implementation, brute force, set
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

using ll = long long int;
using pii = pair<int, int>;
using piii = pair<int, pii>;
using vi = vector<int>;
using vii = vector<pii>;
const int INF = 0x3F3F3F3F;
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const int MAX = 1e5 + 2;

int N, M;
string arr[502], brr[502];

inline int ctoi(char c) {
    switch (c) {
    case 'A':
        return 0;
    case 'C':
        return 1;
    case 'G':
        return 2;
    case 'T':
        return 3;
    }
    return -1;
}

bool mp[4][4][4];

inline bool check(int a, int b, int c) {
    FILL(mp, 0);
    for (int i = 1; i <= N; ++i) {
        mp[ctoi(arr[i][a])][ctoi(arr[i][b])][ctoi(arr[i][c])] = 1;
    }
    for (int i = 1; i <= N; ++i) {
        if (mp[ctoi(brr[i][a])][ctoi(brr[i][b])][ctoi(brr[i][c])]) {
            return 0;
        }
    }
    return 1;
}

int main() {

    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        cin >> arr[i];
    }
    for (int i = 1; i <= N; ++i) {
        cin >> brr[i];
    }

    int ans = 0;
    for (int i = 0; i < M; ++i) {
        for (int j = i + 1; j < M; ++j) {
            for (int k = j + 1; k < M; ++k) {
                ans += check(i, j, k);
            }
        }
    }
    cout << ans << '\n';
}
