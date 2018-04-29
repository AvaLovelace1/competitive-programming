/*
 Solution to CCC '06 J1 - Canadian Calorie Counting by Ava Pun
 Key concepts: implementation
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int choices[4][4] = { {461, 431, 420, 0}, {100, 57, 70, 0}, {130, 160, 118, 0}, {167, 266, 75, 0} };
    
    int choice, total = 0;
    
    for (int i = 0; i < 4; i++) {
        scanf("%d", &choice);
        total += choices[i][choice - 1];
    }
    
    printf("Your total Calorie count is %d.", total);
    
    return 0;
    
}
