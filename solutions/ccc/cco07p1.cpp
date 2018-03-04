/*
 Solution to CCO '07 P1 - Cows by Ava Pun
 Key concepts: geometry, convex hull, shoelace formula
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
const int INF = 0x3F3F3F3F;

int N;
pii arr[10005];
stack<pii> h1, h2;
vector<pii> hull;

int orientation(pii a, pii b, pii c) {
    return (b.second - a.second) * (c.first - b.first) - (c.second - b.second) * (b.first - a.first);
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
    
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d%d", &arr[i].first, &arr[i].second);
    }
    
    sort(arr, arr + N);
    for (int i = 0; i < N; i++) {
        process(arr[i], h1);
    }
    for (int i = N - 1; i >= 0; i--) {
        process(arr[i], h2);
    }
    
    while (h2.size() > 1) {
        hull.push_back(h2.top());
        h2.pop();
    }
    while (h1.size() > 1) {
        hull.push_back(h1.top());
        h1.pop();
    }
    
    double ans = 0;
    for (int i = 0; i < hull.size(); i++) {
        ans += hull[i].first * hull[(i + 1) % hull.size()].second;
    }
    for (int i = 0; i < hull.size(); i++) {
        ans -= hull[(i + 1) % hull.size()].first * hull[i].second;
    }
    ans /= 2;
    
    printf("%d", (int) (ans / 50));
    
    return 0;
}
