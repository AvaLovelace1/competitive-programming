/*
 Solution to Problem-setting Pandemonium (Senior) by Ava Pun
 Key concepts: greedy algorithms
 */

#include <bits/stdc++.h>

using namespace std;

int N;
unordered_map<int, int> arr;

int main() {
    
    scanf("%d", &N);
    int n;
    for (int i = 0; i < N; i++) {
        scanf("%d", &n);
        arr[n]++;
    }

    int ans = 0;
    for (auto i : arr) {
        ans = max(ans, i.second);
    }
    
    printf("%d", ans);
    
    return 0;
}
