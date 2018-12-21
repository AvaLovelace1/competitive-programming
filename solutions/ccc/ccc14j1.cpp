/*
 Solution to CCC '14 J1 - Triangle Times by Ava Pun
 Key concepts: implementation, simple math
 */
 
 #include <bits/stdc++.h>

using namespace std;

int angle1, angle2, angle3;

int main() {
    scanf("%d%d%d", &angle1, &angle2, &angle3);
    
    if (angle1 + angle2 + angle3 != 180) {
        printf("Error");
    } else if (angle1 == angle2 && angle2 == angle3) {
        printf("Equilateral");
    } else if (angle1 == angle2 || angle2 == angle3 || angle1 == angle3) {
        printf("Isosceles");
    } else {
        printf("Scalene");
    }
}
