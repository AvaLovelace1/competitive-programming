/*
 Solution to Sonya and Matrix by Ava Pun
 Key concepts: brute force, constructive algorithms
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

int T;
map<int, int> mp, mp2;

inline bool check(int n, int m, int x, int y) {
    if (x < 1 || x > n || y < 1 || y > m) {
        return 0;
    }
    mp2.clear();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            mp2[abs(i - x) + abs(j - y)]++;
        }
    }
    for (auto p : mp2) {
        if (mp[p.f] != p.s) {
            return 0;
        }
    }
    return 1;
}

int main() {
    
    scanf("%d", &T);
    int k;
    for (int i = 1; i <= T; i++) {
        scanf("%d", &k);
        mp[k]++;
    }
    
    int x = 1;
    for (auto p : mp) {
        if (p.f != 0 && p.s != p.f * 4) {
            x = p.f;
            break;
        }
    }
    int b = (*--mp.end()).f;
    
    for (int n = 1; n * n <= T; n++) {
        if (T % n == 0) {
            int m = T / n;
            int y = m - (b - (n - x));
            if (check(n, m, x, y)) {
                printf("%d %d\n%d %d\n", n, m, x, y);
                return 0;
            }
            if (check(n, m, y, x)) {
                printf("%d %d\n%d %d\n", n, m, y, x);
                return 0;
            }
        }
    }
    printf("-1\n");
    
    return 0;
}
