/*
 Solution to CCC '10 J1 - What is n, Daddy? by Ava Pun
 Key concepts: simple math
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n;
    scanf("%d", &n);
    
    if (n == 1 || n == 9 || n == 10) {
        printf("1");
    } else if (n == 4 || n == 5 || n == 6) {
        printf("3");
    } else {
        printf("2");
    }
    
    return 0;
    
}
