/*
 Solution to CCC '18 J2 - Occupy parking by Ava Pun
 Key concepts: implementation
 */

#include <bits/stdc++.h>

using namespace std;

const int MAX = 105;

int N;
bool arr[MAX];

int main() {

    scanf("%d", &N);
    char c;
    for (int i = 1; i <= N; i++) {
        scanf(" %c", &c);
        arr[i] = c == 'C';
    }
    for (int i = 1; i <= N; i++) {
        scanf(" %c", &c);
        arr[i] &= c == 'C';
    }
    printf("%d\n", accumulate(arr + 1, arr + N + 1, 0));

    return 0;
}
