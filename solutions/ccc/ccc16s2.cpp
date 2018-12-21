/*
 Solution to CCC '16 S2 - Tandem Bicycle by Ava Pun
 Key concepts: implementation, greedy algorithms
 */

#include <bits/stdc++.h>

using namespace std;

int T, N;
int d[101], p[101];

int main() {
    
    scanf("%d%d", &T, &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &d[i]);
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &p[i]);
    }
    
    sort(d, d + N);
    sort(p, p + N);
    
    if (T == 1) {
        int sum = 0;
        for (int i = 0; i < N; i++) {
            sum += max(d[i], p[i]);
        }
        printf("%d", sum);
    } else {
        int sum = 0;
        for (int i = 0; i < N; i++) {
            sum += max(d[i], p[N - 1 - i]);
        }
        printf("%d", sum);
    }
    
    return 0;
}
