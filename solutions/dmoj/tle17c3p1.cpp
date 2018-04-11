/*
 Solution to TLE '17 Contest 3 P1 - Willson and Territory by Ava Pun
 Key concepts: implementation
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int x0, y0, N;
    scanf("%d%d%d", &x0, &y0, &N);
    
    int maxDist = 0, xi, yi;
    for (int i = 0; i < N; i++) {
        scanf("%d%d", &xi, &yi);
        maxDist = max(maxDist, abs(x0 - xi) + abs(y0 - yi));
    }
    
    double ans = pow(sqrt(2 * maxDist * maxDist), 2);
    int ansInt = round(ans);
    
    printf("%d", ansInt);
    
    return 0;
    
}
