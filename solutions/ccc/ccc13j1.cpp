/*
 Solution to CCC '13 J1 - Next in line by Ava Pun
 Key concepts: implementation
 */
 
#include <bits/stdc++.h>
using namespace std;

int youngest, middle;

int main() {
    scanf("%d%d", &youngest, &middle);
    printf("%d", middle + (middle - youngest));
}
