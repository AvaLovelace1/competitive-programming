/*
 Solution to WC15 #1 - Woburn Workload by Ava Pun
 Key concepts: greedy algorithms
 */

#include <bits/stdc++.h>

using namespace std;

int N;
int t[101], d[101];

int main() {
    
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &d[i], &t[i]);
    }
    
    int n = 0, penalty = 0;
    for (int i = 0; i < N; i++) {
        if (n + t[i] > d[i]) {
            penalty += n + t[i] - d[i];
        }
        n = min(n + t[i], d[i]);
    }
    
    printf("%d", penalty);
    
    return 0;
}
