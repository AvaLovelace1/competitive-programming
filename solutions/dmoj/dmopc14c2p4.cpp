/*
 Solution to DMOPC '14 Contest 2 P4 - Deforestation by Ava Pun
 Key concepts: prefix sum array
 */

#include <bits/stdc++.h>

using namespace std;

int N, Q;
int pref[1000005];

int main() {
    
    scanf("%d", &N);
    int n;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &n);
        pref[i] = pref[i - 1] + n;
    }
    
    scanf("%d", &Q);
    int a, b;
    while (Q--) {
        scanf("%d%d", &a, &b);
        printf("%d\n", pref[b + 1] - pref[a]);
    }
    
    return 0;
}
