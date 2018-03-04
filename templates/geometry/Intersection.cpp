/*
 ~ Intersection ~
 
 Do two given line segments intersect?
 I hate geometry.
 
 Time complexity: O(1)
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<pii, pii> piii;
typedef pair<double, double> pdd;
typedef pair<pdd, pdd> pddd;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

pii a1, b1, a2, b2;

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

pdd intersectPoint(pddd a, pddd b) {

    double a1 = a.second.second - a.first.second;
    double b1 = a.first.first - a.second.first;
    double c1 = a1 * (a.first.first) + b1 * (a.first.second);
    
    double a2 = b.second.second - b.first.second;
    double b2 = b.first.first - b.second.first;
    double c2 = a2 * (b.first.first) + b2 * (b.first.second);
    
    double det = a1 * b2 - a2 * b1;
    
    if (det == 0) {
        return {INT64_MAX, INT64_MAX};
    } else {
        double x = (b2 * c1 - b1 * c2) / det;
        double y = (a1 * c2 - a2 * c1) / det;
        return {x, y};
    }
    
}

int main() {
    
    scanf("%d%d%d%d%d%d%d%d", &a1.first, &a1.second, &b1.first, &b1.second, &a2.first, &a2.second, &b2.first, &b2.second);
    
    if (intersects({a1, b1}, {a2, b2})) {
        printf("These line segments intersect.\n");
    } else {
        printf("These line segments don't intersect.\n");
    }
    
    pdd pt = intersectPoint({a1, b1}, {a2, b2});
    
    if (pt.first == INT64_MAX) {
        printf("The lines defined by these line segments are parallel.\n");
    } else {
        printf("The lines defined by these line segments intersect at (%lf, %lf).\n", pt.first, pt.second);
    }
    
    return 0;
    
}
