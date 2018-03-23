/*
 Solution to The Odd Number by Ava Pun
 Key concepts: ad hoc
 */

#include <bits/stdc++.h>

using namespace std;

int N, a, b;

int main() {
    
    scanf("%d%d", &N, &a);
    
    for (int i = 1; i < N; i++) {
        scanf("%d", &b);
        a ^= b;
    }
    
    printf("%d", a);
    
    return 0;
    
}
