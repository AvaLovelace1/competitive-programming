/*
 Solution to COCI '15 Contest 4 #3 Deathstar by Ava Pun
 Key concepts: ad hoc
 */

#include <bits/stdc++.h>

using namespace std;

int N;
int m[1001][1001];

int main() {

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &m[i][j]);
        }
    }
    
    int ans;
    for (int i = 0; i < N; i++) {
        ans = 0;
        for (int j = 0; j < N; j++) {
            ans |= m[i][j];
        }
        printf("%d ", ans);
    }
    
    return 0;
    
}
