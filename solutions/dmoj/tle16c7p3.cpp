/*
 Solution to TLE '16 Contest 7 P3 - NOR by Ava Pun
 Key concepts: ad hoc
 */

#include <bits/stdc++.h>

using namespace std;

int N, Q;
bool arr[1000001];
int counts[1000001];

bool nor(int start, int end) {
    if (counts[end] < start) {
        if ((end - start + 1) & 1) {
            return false;
        } else {
            return true;
        }
    } else if (counts[end] == start) {
        if ((end - counts[end]) & 1) {
            return false;
        } else {
            return true;
        }
    } else if ((end - counts[end]) & 1) {
        return true;
    } else {
        return false;
    }
}

int main() {

    scanf("%d", &N);
    
    int tmp;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &tmp);
        arr[i] = tmp;
    }
    
    int a = 0;
    for (int i = 1; i <= N; i++) {
        if (arr[i] == 1) {
            a = i;
        }
        counts[i] = a;
    }
    
    scanf("%d", &Q);
    
    int x, y;
    while (Q--) {
        scanf("%d%d", &x, &y);
        printf("%d\n", nor(x, y));
    }
    
    return 0;
    
}
