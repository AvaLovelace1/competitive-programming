/*
 Solution to Mock CCO '18 Contest 2 Problem 4 - Victor's Rectangles by Ava Pun
 Key concepts: geometry
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
const int MAX = 1505;

int N;
int x[MAX], y[MAX];
piii mpVal[MAX][MAX];
pii sorted[MAX * (MAX - 1) / 2];
int cnt = 0;

inline bool valComp(pii a, pii b) {
    return mpVal[a.f][a.s] < mpVal[b.f][b.s];
}

inline bool comp(pii a, pii b) {
    pii a1 = {x[a.f], y[a.f]}, b1 = {x[b.f], y[b.f]};
    return a1 < b1;
}

int main() {
    
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d%d", &x[i], &y[i]);
        x[i] += 1e8, y[i] += 1e8;
    }
    
    for (int i0 = 1; i0 <= N; i0++) {
        for (int j0 = i0 + 1; j0 <= N; j0++) {
            
            if (x[i0] == x[j0] && y[i0] == y[j0]) {
                continue;
            }
            int i = i0, j = j0;
            if (x[i] > x[j]) {
                swap(i, j);
            } else if (x[i] == x[j] && y[i] > y[j]) {
                swap(i, j);
            }
            int rise = y[j] - y[i], run = x[j] - x[i];
            if (rise == 0 || (ll) rise * run > 0) {
                continue;
            }
            
            if (run == 0) {
                rise = 1;
            } else {
                int gcd = abs(__gcd(rise, run));
                rise /= gcd, run /= gcd;
            }
            if (rise < 0) {
                rise = -rise, run = -run;
            }
            
            int xip, yip, xjp, yjp, shift;
            if (run == 0) {
                shift = x[i] / rise;
            } else {
                shift = min(x[i] / rise, y[j] / -run);
            }
            
            run = -run;
            xip = x[i] - shift * rise;
            yip = y[i] - shift * run;
            xjp = x[j] - shift * rise;
            yjp = y[j] - shift * run;
            mpVal[i][j] = {{xip, yip}, {xjp, yjp}};
            sorted[cnt++] = {i, j};
            
        }
    }
    sort(sorted, sorted + cnt, valComp);
    
    ll ans = 0;
    int i = 0;
    while (i < cnt) {
        pii a = sorted[i], b = sorted[i];
        piii val = mpVal[a.f][a.s];
        while (i < cnt && mpVal[sorted[i].f][sorted[i].s] == val) {
            a = min(a, sorted[i], comp);
            b = max(b, sorted[i], comp);
            i++;
        }
        if (a != b) {
            ans = max(ans, abs((ll) (x[b.s] - x[a.f]) * (y[b.f] - y[a.s])) -
                      abs((ll) (x[a.s] - x[a.f]) * (y[a.f] - y[a.s])) -
                      abs((ll) (x[b.f] - x[a.f]) * (y[b.f] - y[a.f])));
        }
    }
    printf("%lld\n", ans);
    
    return 0;
}
