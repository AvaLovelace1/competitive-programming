/*
 Solution to Mock CCC '18 Contest 2 J4/S2 - A Geometry Problem by Ava Pun
 Key concepts: implementation, geometry
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int l1, w1, l2, w2, l3, w3;

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

bool arrange(int a1, int a2, int a3, int h1, int h2, int h3) {
    if (a1 == a2 + a3 && a1 == h1 + h2 && h2 == h3) {
        return true;
    }
    return false;
}

int main() {
   
    scanf("%d%d%d%d%d%d", &l1, &w1, &l2, &w2, &l3, &w3);
    
    if (l1 < w1) {
        swap(l1, w1);
    }
    if (l2 < w2) {
        swap(l2, w2);
    }
    if (l3 < w3) {
        swap(l3, w3);
    }
    
    bool ans = false;
    if (l1 == l2 && l2 == l3 && w1 + w2 + w3 == l1) {
        ans = true;
    } else if (arrange(l1, l2, l3, w1, w2, w3) || arrange(l1, w2, w3, w1, l2, l3) ||
               arrange(l1, l2, w3, w1, w2, l3) || arrange(l1, w2, l3, w1, l2, w3) ||
               arrange(l2, l1, l3, w2, w1, w3) || arrange(l2, w1, w3, w2, l1, l3) ||
               arrange(l2, w1, l3, w2, l1, w3) || arrange(l2, l1, w3, w2, w1, l3) ||
               arrange(l3, l2, l1, w3, w2, w1) || arrange(l3, w2, w1, w3, l2, l1) ||
               arrange(l3, w2, l1, w3, l2, w1) || arrange(l3, l2, w1, w3, w2, l1)) {
        ans = true;
    }
    
    printf(ans ? "YES\n" : "NO\n");
    
    return 0;
}
