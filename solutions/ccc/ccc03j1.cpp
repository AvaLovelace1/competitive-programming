/*
 Solution to CCC '03 J1 - Trident by Ava Pun
 Key concepts: implementation
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int t, s, h;
    scanf("%d%d%d", &t, &s, &h);
    
    for (int i = 1; i <= t; i++) {

        printf("*");
        for (int k = 1; k <= s; k++) {
            printf(" ");
        }
        printf("*");
        for (int k = 1; k <= s; k++) {
            printf(" ");
        }
        printf("*");
        printf("\n");
    }
    for (int i = 1; i <= 3 + 2 * s; i++) {
        printf("*");
    }
    printf("\n");
    for (int i = 1; i <= h; i++) {
        printf(" ");
        for (int k = 1; k <= s; k++) {
            printf(" ");
        }
        printf("*");
        printf("\n");
    }
    return 0;
    
}
