/*
 Solution to ECOO '15 R2 P3 - Lucas' Other Tower by Ava Pun
 Key concepts: ad hoc
 */

#include <bits/stdc++.h>

using namespace std;

int N, T;

int main() {
    
    for (int i = 1; i <= 10; i++) {
        scanf("%d%d", &N, &T);
        printf("%d\n", 2 * (N - 1) + 1);
    }
    
    return 0;
    
}
