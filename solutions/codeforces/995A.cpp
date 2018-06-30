/*
 Solution to Tesla by Ava Pun
 Key concepts: ad hoc
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
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 55;

int N, K;
int arr[5][MAX];
vector<piii> ans;

inline void move(pii rc, pii rc1) {
    int r = rc.f, c = rc.s, r1 = rc1.f, c1 = rc1.s;
    if (arr[r][c] != 0 && (arr[r1][c1] == 0 || arr[r1][c1] == arr[r][c])) {
        ans.pb({arr[r][c], {r1, c1}});
        arr[r1][c1] = arr[r][c];
        arr[r][c] = 0;
    }
}

inline int park() {
    int ret = 0;
    for (int i = 1; i <= N; i++) {
        move({2, i}, {1, i});
        move({3, i}, {4, i});
    }
    for (int i = 1; i <= N; i++) {
        ret += arr[2][i] != 0;
        ret += arr[3][i] != 0;
    }
    return ret;
}

inline pii prev(pii rc) {
    int r = rc.f, c = rc.s;
    if (r == 2) {
        if (c == 1) {
            return {3, 1};
        } else {
            return {r, c - 1};
        }
    } else {
        if (c == N) {
            return {2, N};
        } else {
            return {r, c + 1};
        }
    }
}

inline pii next(pii rc) {
    int r = rc.f, c = rc.s;
    if (r == 2) {
        if (c == N) {
            return {3, N};
        } else {
            return {r, c + 1};
        }
    } else {
        if (c == 1) {
            return {2, 1};
        } else {
            return {r, c - 1};
        }
    }
}

int main() {
    
    scanf("%d%d", &N, &K);
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &arr[i][j]);
            if ((i == 1 || i == 4) && arr[i][j] == 0) {
                arr[i][j] = -1;
            }
        }
    }
    
    if (K == 2 * N && park() == K) {
        printf("-1\n");
        return 0;
    }
    
    while (park()) {
        pii rc = {2, 1};
        while (arr[next(rc).f][next(rc).s] != 0) {
            rc = next(rc);
        }
        int cnt = 0;
        while (cnt < 2 * N - 1) {
            move(rc, next(rc));
            rc = prev(rc);
            cnt++;
        }
    }
    
    printf("%d\n", (int) ans.size());
    for (piii p : ans) {
        printf("%d %d %d\n", p.f, p.s.f, p.s.s);
    }
    
    return 0;
}
