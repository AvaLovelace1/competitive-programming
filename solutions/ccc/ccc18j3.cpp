/*
 Solution to CCC '18 J3 - Are we there yet? by Ava Pun
 Key concepts: implementation
 */

#include <bits/stdc++.h>

using namespace std;

const int MAX = 105;

int arr[6];

int dist(int i, int j) {
    if (i > j) {
        swap(i, j);
    }
    return accumulate(arr + i, arr + j, 0);
}

int main() {

    for (int i = 1; i <= 4; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            printf("%d ", dist(i, j));
        }
        printf("\n");
    }

    return 0;
}
