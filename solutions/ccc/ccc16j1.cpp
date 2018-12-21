/*
 Solution to CCC '16 J1 - Tournament Selection by Ava Pun
 Key concepts: implementation
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    
    char c;
    int gamesWon = 0;
    
    for (int i = 1; i <= 6; i++) {
        scanf(" %c", &c);
        if (c == 'W') {
            gamesWon++;
        }
    }
    
    if (gamesWon >= 5) {
        printf("1");
    } else if (gamesWon >= 3) {
        printf("2");
    } else if (gamesWon >= 1) {
        printf("3");
    } else {
        printf("-1");
    }
    
    return 0;
    
}
