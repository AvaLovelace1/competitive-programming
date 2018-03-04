/*
 Solution to CCO '13 P4 - A Romantic Movie Outing by Ava Pun
 Key concepts: binary indexed tree
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 5e5 + 5;
const int MAXR = 1500;

int L, T;
int tree[2505][2505];
bool taken[1505][1005];

void update(int r, int c, int x) {
    for (int i = r; i <= 2501; i += i & -i) {
        for (int j = c; j <= 2501; j += j & -j) {
            tree[i][j] += x;
        }
    }
}

int query(int r, int c) {
    int ans = 0;
    for (int i = r; i > 0; i -= i & -i) {
        for (int j = c; j > 0; j -= j & -j) {
            ans += tree[i][j];
        }
    }
    return ans;
}

pii conv(int r, int c) {
    return {r + c - 1, r - c + 1001};
}

int main() {
    
    scanf("%d%d", &L, &T);
    
    char c;
    int a, b;
    
    while (T--) {
        scanf(" %c%d%d", &c, &a, &b);
        pii p = conv(a, b);
        if (c == 'E') {
            if (a <= MAXR) {
                update(p.first, p.second, 1);
                taken[a][b] = true;
            }
        } else if (c == 'L') {
            if (a <= MAXR) {
                update(p.first, p.second, -1);
                taken[a][b] = false;
            }
        } else if (c == 'S') {
            if (taken[a][b] || taken[a][b + 1]) {
                printf("No\n");
            } else {
                pii p1 = conv(a, b + 1);
                printf("%d\n", query(p.first, p.second) + query(p1.first, p1.second));
            }
        }
    }
    
    int ans1 = INF, ans2 = INF;
    for (int i = L + 1; i <= L + 501; i++) {
        for (int j = 1; j <= 1000; j++) {
            if (!taken[i][j]) {
                pii p = conv(i, j);
                int num = query(p.first, p.second);
                if (num <= ans1) {
                    ans2 = ans1;
                    ans1 = num;
                } else if (num < ans2) {
                    ans2 = num;
                }
            }
        }
    }
    
    printf("%d", ans1 + ans2);
    
    return 0;
    
}
