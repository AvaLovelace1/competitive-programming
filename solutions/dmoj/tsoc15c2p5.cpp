/*
 Solution to TSOC '15 Contest 2 #5 - Bebiliths by Ava Pun
 Key concepts: sorting, data structures
 */

#include <bits/stdc++.h>

using namespace std;

int S, N, Q;

struct bebilith {
    int speed, venom, sharp, num;
};

bebilith arr[50001];

bool comp(bebilith a, bebilith b) {
    if (a.speed != b.speed) {
        return a.speed > b.speed;
    } else if (a.speed < S) {
        if (a.venom == b.venom) {
            return a.num < b.num;
        } else {
            return a.venom > b.venom;
        }
    } else {
        if (a.sharp == b.sharp) {
            return a.num < b.num;
        } else {
            return a.sharp > b.sharp;
        }
    }
}

int main() {
    
    scanf("%d%d", &S, &N);
    int a, b, c;
    for (int i = 0; i < N; i++) {
        scanf("%d%d%d", &a, &b, &c);
        arr[i].speed = a;
        arr[i].venom = b;
        arr[i].sharp = c;
        arr[i].num = i + 1;
    }
    
    sort(arr, arr + N, comp);
    
    scanf("%d", &Q);
    while (Q--) {
        scanf("%d", &a);
        printf("%d\n", arr[a - 1].num);
    }
    
    return 0;
}
