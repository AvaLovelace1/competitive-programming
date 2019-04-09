/*
 Solution to CCC '13 S3 - Chances of Winning by Ava Pun
 Key concepts: brute force backtracking
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3f3f3f3f;
const int MAX = 1e5 + 5;

int T, G;
bool played[5][5];
int pts[5];
vii rem;

inline void place(int a, int b, int sa, int sb) {
    pts[a] += sa, pts[b] += sb;
}
inline void unplace(int a, int b, int sa, int sb) {
    pts[a] -= sa, pts[b] -= sb;
}

int solve(int n) {
    if (n >= rem.size()) {
        int maxN = *max_element(pts + 1, pts + 5);
        for (int i = 1; i <= 4; i++) {
            if (pts[i] == maxN && i != T) {
                return 0;
            }
        }
        return 1;
    }
    int ans = 0;
    place(rem[n].f, rem[n].s, 3, 0);
    ans += solve(n + 1);
    unplace(rem[n].f, rem[n].s, 3, 0);
    place(rem[n].f, rem[n].s, 0, 3);
    ans += solve(n + 1);
    unplace(rem[n].f, rem[n].s, 0, 3);
    place(rem[n].f, rem[n].s, 1, 1);
    ans += solve(n + 1);
    unplace(rem[n].f, rem[n].s, 1, 1);
    return ans;
}

int main() {

    scanf("%d%d", &T, &G);
    int a, b, sa, sb;
    for (int i = 1; i <= G; i++) {
        scanf("%d%d%d%d", &a, &b, &sa, &sb);
        if (sa > sb) {
            pts[a] += 3;
        } else if (sb > sa) {
            pts[b] += 3;
        } else {
            pts[a]++, pts[b]++;
        }
        played[a][b] = played[b][a] = 1;
    }
    for (int i = 1; i <= 4; i++) {
        for (int j = i + 1; j <= 4; j++) {
            if (!played[i][j]) {
                rem.pb({i, j});
            }
        }
    }
    printf("%d\n", solve(0));

    return 0;
}
