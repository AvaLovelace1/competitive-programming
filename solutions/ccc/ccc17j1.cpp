/*
 Solution to CCC '17 J1 - Quadrant Selection by Ava Pun
 Key concepts: implementation
 */

#include <bits/stdc++.h>

using namespace std;

int X, Y;

int main() {
    
    scanf("%d%d", &X, &Y);
    
    if (X < 0) {
        if (Y < 0) {
            printf("3");
        } else {
            printf("2");
        }
    } else {
        if (Y < 0) {
            printf("4");
        } else {
            printf("1");
        }
    }
    
    return 0;
    
}
