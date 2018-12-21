/*
 Solution to CCC '96 S1 - Deficient, Perfect, and Abundant by Ava Pun
 Key concepts: implementation, simple math
 */

#include <bits/stdc++.h>

using namespace std;

int N;

int main() {
    
    scanf("%d", &N);
    int n, sum;
    string s;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &n);
        sum = 1;
        for (int j = 2; j * j <= n; j++) {
            if (n % j == 0) {
                sum += j;
                if (j * j != n) {
                    sum += n / j;
                }
            }
        }
        if (sum < n) {
            printf("%d is a deficient number.\n", n);
        } else if (sum > n) {
            printf("%d is an abundant number.\n", n);
        } else {
            printf("%d is a perfect number.\n", n);
        }
    }
    
    return 0;
    
}
