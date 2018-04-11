/*
 Solution to Battle Positions by Ava Pun
 Key concepts: difference array
 */

#include <bits/stdc++.h>

using namespace std;

int I, N, J;
int diff[100005] = {};

int main() {
    
    scanf("%d%d%d", &I, &N, &J);
    
    int l, r, k;
    while (J--) {
        scanf("%d%d%d", &l, &r, &k);
        diff[l] += k;
        diff[r + 1] -= k;
    }
    
    int sum = 0, count = 0;
    for (int i = 1; i <= I; i++) {
        sum += diff[i];
        if (sum < N) {
            count++;
        }
    }
    
    printf("%d", count);
    
    return 0;
}
