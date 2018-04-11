/*
 Solution to TLE '17 Contest 3 P3 - Fax's Thanksgiving Dish by Ava Pun
 Key concepts: graph theory
 */

#include <bits/stdc++.h>

using namespace std;

int N, M;
int nums[300001];
vector<int> adj[300001];

int findLeast(int targ) {
    int least = INT_MAX;
    for (int n : adj[targ]) {
        least = min(least, findLeast(n));
    }
    if (least == INT_MAX) {
        least = 0;
    }
    least += nums[targ];
    return least;
}

int main() {
    
    scanf("%d%d", &N, &M);
    
    int targ, num, item;
    for (int i = 0; i < M; i++) {
        scanf("%d%d", &targ, &num);
        for (int j = 0; j < num; j++) {
            scanf("%d", &item);
            adj[targ].push_back(item);
        }
    }
    
    for (int i = 1; i <= N; i++) {
        scanf("%d", &nums[i]);
    }
    
    printf("%d", findLeast(1));
    
    return 0;
    
}
