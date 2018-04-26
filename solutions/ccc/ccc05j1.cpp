/*
 Solution to CCC '05 J1 - The Cell Sell by Ava Pun
 Key concepts: implementation, simple math
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int daytime, evening, weekend;
    scanf("%d%d%d", &daytime, &evening, &weekend);
    
    double A = 0, B = 0;
    
    if (daytime > 100) {
        A += (daytime - 100) * 0.25;
    }
    A += evening * 0.15 + weekend * 0.2;
    
    if (daytime > 250) {
        B += (daytime - 250) * 0.45;
    }
    B += evening * 0.35 + weekend * 0.25;
    
    A = round(A * 100) / 100;
    B = round(B * 100) / 100;
    
    printf("Plan A costs %.2lf\n", A);
    printf("Plan B costs %.2lf\n", B);
    
    if (A < B) {
        printf("Plan A is cheapest.");
    } else if (B < A) {
        printf("Plan B is cheapest.");
    } else {
        printf("Plan A and B are the same price.");
    }
    
    return 0;
    
}
