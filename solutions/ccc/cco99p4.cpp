/*
 Solution to CCC '99 P4 - Maple Syrup Roundup by Ava Pun
 Key concepts: geometry, convex hull
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;

int T, N;
pii arr[101];

int orientation(pii a, pii b, pii c) {
    return (b.second - a.second) * (c.first - b.first) - (c.second - b.second) * (b.first - a.first);
}

double dist(pii a, pii b) {
    return sqrt(pow(b.first - a.first, 2) + pow(b.second - a.second, 2));
}

double findDist(stack<pii> &s) {
    double ans = 0;
    pii a = s.top(), b;
    s.pop();
    while (!s.empty()) {
        b = s.top();
        s.pop();
        ans += dist(a, b);
        a = b;
    }
    return ans;
}

void process(pii p, stack<pii> &s) {
    bool cw = false;
    while (s.size() > 1 && !cw) {
        pii b = s.top();
        s.pop();
        pii a = s.top();
        if (orientation(a, b, p) > 0) {
            cw = true;
            s.push(b);
        }
    }
    s.push(p);
}

int main() {
    
    scanf("%d", &T);
    
    while (T--) {
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            scanf("%d%d", &arr[i].first, &arr[i].second);
        }
        sort(arr, arr + N);
        stack<pii> h1, h2;
        for (int i = 0; i < N; i++) {
            process(arr[i], h1);
        }
        for (int i = N - 1; i >= 0; i--) {
            process(arr[i], h2);
        }
        printf("%.2lf\n", findDist(h1) + findDist(h2));
    }
    
    return 0;
    
}
