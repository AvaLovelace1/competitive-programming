/*
 Solution to TLE '17 Contest 4 P1 - Riding the Curve by Ava Pun
 Key concepts: simple math
 */

#include <bits/stdc++.h>

using namespace std;

int M, K, N;

int main() {
    
    scanf("%d%d%d", &M, &K, &N);
    
    int x = (int) ceil(0.595 * N - K);
    if (x < 0) {
        x = 0;
    }
    if (x > M) {
        printf("have mercy snew");
    } else {
        printf("%d", x);
    }
    
    return 0;
    
}
