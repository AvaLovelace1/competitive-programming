/*
 Solution to Lamppost by Ava Pun
 Key concepts: graph theory
 */

#include <bits/stdc++.h>

using namespace std;

int N, C;
int deg[1000001];

int main() {

    scanf("%d%d", &N, &C);
    int a, b;
    for (int i = 1; i <= C; i++) {
        scanf("%d%d", &a, &b);
        deg[a]++;
        deg[b]++;
    }
    
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (deg[i] >= deg[ans]) {
            ans = i;
        }
    }
    
    printf("%d", ans);
    
    return 0;
}
