/*
 Solution to CCC '15 J1 - Special Day by Ava Pun
 Key concepts: implementation
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int month, day;
    scanf("%d%d", &month, &day);
    
    if (month == 2 && day == 18) {
        printf("Special");
    } else if (month < 2 || (month == 2 && day < 18)) {
        printf("Before");
    } else {
        printf("After");
    }
    
    return 0;
    
}
