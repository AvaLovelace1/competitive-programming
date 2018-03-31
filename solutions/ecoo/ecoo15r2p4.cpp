/*
 Solution to ECOO '15 R2 P4 - Rectangle Roundup by Ava Pun
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
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;

int N;
set<piii> arr[35];
set<piii> used;
queue<piii> q;

void push(int xp, int yp, int mc, int mn) {
    if (xp > yp) {
        swap(xp, yp);
    }
    piii p = {{xp, yp}, mc | mn};
    q.push(p);
    arr[xp].insert(p);
    arr[yp].insert(p);
}

void process(set<piii> &ss, piii curr) {
    
    for (piii next : ss) {
        if (!(curr.s & next.s)) {
            
            int xc = curr.f.f, yc = curr.f.s;
            int xn = next.f.f, yn = next.f.s;
            
            for (int i = 1; i <= 2; i++) {
                if (xn == xc) {
                    int xp = xc, yp = yn + yc;
                    push(xp, yp, curr.s, next.s);
                }
                if (yn == yc) {
                    int xp = xn + xc, yp = yc;
                    push(xp, yp, curr.s, next.s);
                }
                swap(xn, yn);
            }
            
        }
    }
    
}

int main() {
    
    for (int test = 1; test <= 10; test++) {
        
        for (int i = 0; i < 35; i++) {
            arr[i].clear();
        }
        used.clear();
        while (!q.empty()) {
            q.pop();
        }
        
        scanf("%d", &N);
        int x, y;
        for (int i = 0; i < N; i++) {
            piii p;
            scanf("%d%d", &x, &y);
            if (x > y) {
                swap(x, y);
            }
            p = {{x, y}, 1 << i};
            arr[x].insert(p);
            arr[y].insert(p);
            q.push(p);
        }
        
        int ans = -1;
        
        while (!q.empty()) {
            
            piii curr = q.front();
            q.pop();
            x = curr.f.f;
            y = curr.f.s;
            
            if (curr.s == (1 << N) - 1) {
                ans = max(ans, 2 * (x + y));
            } else if (used.find(curr) == used.end()) {
                used.insert(curr);
                process(arr[x], curr);
                process(arr[y], curr);
            }
            
        }
        
        if (ans == -1) {
            printf("Not Possible\n");
        } else {
            printf("%d\n", ans);
        }
        
    }
    
    return 0;
}
