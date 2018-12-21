/*
 Solution to CCC '18 J1 - Telemarketer or not? by Ava Pun
 Key concepts: implementation
 */

#include <bits/stdc++.h>

using namespace std;

int arr[5];

int main() {

    for (int i = 1; i <= 4; i++) {
        scanf("%d", &arr[i]);
    }
    printf((arr[1] == 8 || arr[1] == 9) && arr[2] == arr[3] && (arr[4] == 8 || arr[4] == 9) ? "ignore\n" : "answer\n");

    return 0;
}
