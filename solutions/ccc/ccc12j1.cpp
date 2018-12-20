/*
 Solution to CCC '12 J1 - Speed fines are not fine! by Ava Pun
 Key concepts: implementation
 */
 
 #include <bits/stdc++.h>

using namespace std;

int main() {
    
    int limit, speed;
    scanf("%d%d", &limit, &speed);
    
    if (speed <= limit) {
        printf("Congratulations, you are within the speed limit!");
    } else if (speed - limit >= 31) {
        printf("You are speeding and your fine is $500.");
    } else if (speed - limit >= 21) {
        printf("You are speeding and your fine is $270.");
    } else {
        printf("You are speeding and your fine is $100.");
    }
    
    return 0;
    
}
