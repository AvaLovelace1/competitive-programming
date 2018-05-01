/*
 Solution to CCC '06 S3 - Tin Can Telephone by Ava Pun
 Key concepts: geometry
 */

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, pii> piii;

int N;
piii L;
vector<piii> edges[101];

int orientation(pii a, pii b, pii c) {
    int val = (b.second - a.second) * (c.first - b.first) - (b.first - a.first) * (c.second - b.second);
    if (val == 0) {
        return 0;
    } else {
        return val > 0 ? 1 : -1;
    }
}

bool onSegment(piii seg, pii p) {
    if (p.first >= min(seg.first.first, seg.second.first) && p.first <= max(seg.first.first, seg.second.first)
        && p.second >= min(seg.first.second, seg.second.second) && p.second <= max(seg.first.second, seg.second.second)) {
        return true;
    } else {
        return false;
    }
}

bool intersects(piii a, piii b) {
    int o1 = orientation(a.first, b.first, a.second);
    int o2 = orientation(a.first, b.second, a.second);
    int o3 = orientation(b.first, a.first, b.second);
    int o4 = orientation(b.first, a.second, b.second);
    if (o1 != o2 && o3 != o4) {
        return true;
    } else if ((o1 == 0 && onSegment(a, b.first)) || (o2 == 0 && onSegment(a, b.second)) ||
               (o1 == 0 && onSegment(b, a.first)) || (o1 == 0 && onSegment(b, a.second))) {
        return true;
    } else {
        return false;
    }
}

int main() {
    
    scanf("%d%d%d%d%d", &L.first.first, &L.first.second, &L.second.first, &L.second.second, &N);
    
    int n, x, y;
    pii a = {0, 0}, b = {0, 0}, f;
    for (int i = 0; i < N; i++) {
        scanf("%d", &n);
        scanf("%d%d", &x, &y);
        a = {x, y};
        f = a;
        for (int j = 1; j < n; j++) {
            scanf("%d%d", &x, &y);
            b = {x, y};
            edges[i].push_back({a, b});
            a = b;
        }
        edges[i].push_back({b, f});
    }
    
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (piii edge : edges[i]) {
            if (intersects(L, edge)) {
                count++;
                break;
            }
        }
    }
    
    printf("%d", count);
    
    return 0;
}
