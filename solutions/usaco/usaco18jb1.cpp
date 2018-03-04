/*
 Solution to USACO '18 January B1 - Blocked Billboard II by Ava Pun
 Key concepts: implementation, geometry
 */
 
#include <bits/stdc++.h>

using namespace std;

int x, y, xx, yy, a, b, aa, bb;

int main() {
    
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);
    
    scanf("%d%d%d%d%d%d%d%d", &x, &y, &xx, &yy, &a, &b, &aa, &bb);
    
    int area = (xx - x) * (yy - y);
    if (xx <= a || aa <= x || yy <= b || bb <= y) {
        printf("%d", area);
    } else if (x >= a && xx <= aa && y >= b && yy <= bb) {
        printf("0");
    } else if (x < a && xx > aa && y < b && yy > bb) {
        printf("%d", area);
    } else if (x < a && xx > a && xx < aa) {
        if (yy <= bb && y >= b) {
            printf("%d", area - (yy - y) * (xx - a));
        } else {
            printf("%d", area);
        }
    } else if (xx > aa && x < aa && x > a) {
        if (yy <= bb && y >= b) {
            printf("%d", area - (yy - y) * (aa - x));
        } else {
            printf("%d", area);
        }
    } else if (x >= a && xx <= aa) {
        if (y < b && yy <= bb) {
            printf("%d", area - (yy - b) * (xx - x));
        } else if (yy > bb && y >= b) {
            printf("%d", area - (bb - y) * (xx - x));
        } else {
            printf("%d", area);
        }
    } else {
        printf("%d", area);
    }
    
    return 0;
}
