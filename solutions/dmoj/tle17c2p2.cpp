/*
 Solution to TLE '17 Contest 2 P2 - Unlucky Numbers by Ava Pun
 Key concepts: implementation, binary search
 */

#include <bits/stdc++.h>

using namespace std;

int K, N;
int unlucky[500001];

int main() {
    
    scanf("%d", &K);
    for (int i = 0; i < K; i++) {
        scanf("%d", &unlucky[i]);
    }
    
    sort(unlucky, unlucky + K);
    scanf("%d", &N);
    
    int apartment;
    for (int i = 0; i < N; i++) {
        scanf("%d", &apartment);
        
        int greater = upper_bound(unlucky, unlucky + K, apartment) - unlucky;
        apartment -= greater;
        
        printf("%d\n", apartment);
        
    }
    
    
    return 0;
}
