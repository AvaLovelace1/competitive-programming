/*
 Solution to CCO '12 P5 - Sample Size by Ava Pun
 Key concepts: brute force
 */

#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 5;

int M;
bool memo[101][101];
bool good[101];

int main() {
    
    for (int i = 1; i <= 100; i++) {
        for (int j = 0; j <= i; j++) {
            memo[(int) roundl((long double) j / i * 100)][i] = 1;
        }
    }
    
    scanf("%d", &M);
    fill(good + 1, good + 101, 1);
    int n;
    for (int i = 1; i <= M; i++) {
        scanf("%d", &n);
        for (int j = 1; j <= 100; j++) {
            good[j] &= memo[n][j];
        }
    }
    printf("%d\n", (int) (max_element(good + 1, good + 101) - good));
    
    return 0;
}
