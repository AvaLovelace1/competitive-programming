/*
 Solution to TLE '17 Contest 3 P2 - Sectors by Ava Pun
 Key concepts: implementation
 */

#include <bits/stdc++.h>

using namespace std;
int S, K;
map<int, int> sectors;

int main() {
    
    scanf("%d%d", &S, &K);
    
    int s;
    for (int i = 0; i < S; i++) {
        scanf("%d", &s);
        sectors[s] = i;
    }
    
    int pos = 0;
    int hideout;
    long long int dist = 1;
    for (int i = 0; i < K; i++) {
        scanf("%d", &hideout);
        if (i == 0) {
            pos = sectors[hideout];
        }
        dist += abs(pos - sectors[hideout]);
        pos = sectors[hideout];
    }
    
    printf("%lld", dist);
    
    return 0;
}
