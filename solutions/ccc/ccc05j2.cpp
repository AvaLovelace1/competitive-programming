/*
 Solution to CCC '05 J2 - RSA Numbers by Ava Pun
 Key concepts: implementation, simple math
 */

#include <bits/stdc++.h>

using namespace std;

int A, B;

int main() {
    
    scanf("%d%d", &A, &B);
    
    int count = 0;
    for (int n = A; n <= B; n++) {
        int div = 0;
        for (int i = 1; i <= n; i++) {
            if (!(n % i)) {
                div++;
            }
        }
        if (div == 4) {
            count++;
        }
    }
    
    printf("The number of RSA numbers between %d and %d is %d", A, B, count);
    
    return 0;
    
}
