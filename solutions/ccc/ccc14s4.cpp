/*
 Solution to CCC '14 S4 - Tinted Glass Window by Ava Pun
 Key concepts: line sweep
 */
 
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, bool> pii;

struct rect {
    int xl, yt, xr, yb, t;
};

int N, T;
pii points[2005];
rect arr[1005];
int y[2005];
unordered_map<int, int> fromY;
int diff[2005], sum[2005];

int getX(pii a) {
    return a.second ? arr[a.first].xl : arr[a.first].xr;
}

bool comp(pii a, pii b) {
    return getX(a) < getX(b);
}

int main() {
    
    scanf("%d%d", &N, &T);
    int xl, yt, xr, yb, t;
    for (int i = 0; i < N; i++) {
        scanf("%d%d%d%d%d", &xl, &yt, &xr, &yb, &t);
        points[i] = {i, 1};
        points[i + N] = {i, 0};
        y[i] = yt;
        y[i + N] = yb;
        arr[i] = {xl, yt, xr, yb, t};
    }
    
    sort(y, y + 2 * N);
    for (int i = 0; i < 2 * N; i++) {
        fromY[y[i]] = i;
    }
    sort(points, points + 2 * N, comp);
    
    int prev = 0;
    ll ans = 0;
    for (int i = 0; i < 2 * N; i++) {
        int x = getX(points[i]);
        int r = points[i].first;
        if (x != prev) {
            sum[0] = diff[0];
            for (int i = 1; i < 2 * N; i++) {
                sum[i] = sum[i - 1] + diff[i];
            }
            for (int i = 0; i < 2 * N; i++) {
                if (sum[i] >= T) {
                    ans += (ll) (x - prev) * (y[i + 1] - y[i]);
                }
            }
            prev = x;
        }
        int start = fromY[arr[r].yt];
        int end = fromY[arr[r].yb];
        if (points[i].second) {
            diff[start] += arr[r].t;
            diff[end] -= arr[r].t;
        } else {
            diff[start] -= arr[r].t;
            diff[end] += arr[r].t;
        }
    }
    
    printf("%lld", ans);
    
    return 0;
    
}
