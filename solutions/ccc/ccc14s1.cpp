/*
 Solution to CCC '14 S1 - Party Invitation by Ava Pun
 Key concepts: implementation
 */

#include <bits/stdc++.h>

using namespace std;

int K, M;
bool out[105];

int main() {
    
    scanf("%d%d", &K, &M);
    int r;
    while (M--) {
        scanf("%d", &r);
        int cnt = 0;
        for (int i = 1; i <= K; i++) {
            if (!out[i]) {
                cnt++;
                if (cnt % r == 0) {
                    out[i] = 1;
                }
            }
        }
    }
    for (int i = 1; i <= K; i++) {
        if (!out[i]) {
            printf("%d\n", i);
        }
    }
    
    return 0;
}
