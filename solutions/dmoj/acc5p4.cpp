/*
 Solution to Another Contest 5 Problem 4 - Tudor Interacts With Poop by Ava Pun
 Key concepts: simple math
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

int T;
int N = 30;

inline void quer(int k, vii &pts, vi &ans) {
    printf("? %d", k);
    for (auto p : pts) {
        printf(" %d %d", p.f, p.s);
    }
    printf("\n");
    fflush(stdout);
    ans.resize(k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &ans[i]);
        if (ans[i] == -1) {
            exit(0);
        }
    }
}

inline void answer(int a) {
    printf("! %d\n", a);
    fflush(stdout);
}

int main() {
    
    scanf("%d", &T);
    vii pts = {{0, 0}, {N, 0}, {0, N}}, pts2(1);
    vi ans(3), ans2(1);
    while (T--) {
        quer(3, pts, ans);
        pts2[0] = {(ans[0] + (N - ans[1])) / 2, 0};
        quer(1, pts2, ans2);
        int x1 = ans[0] - ans2[0], x2 = (N - ans[1]) + ans2[0];
        int y1 = ans2[0], y2 = (N - ans[2]) + x1;
        answer((x2 - x1) * (y2 - y1));
    }
    
    return 0;
}
