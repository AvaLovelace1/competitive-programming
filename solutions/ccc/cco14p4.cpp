/*
 Solution to CCO '14 P4 - Where's That Fuel? by Ava Pun
 Key concepts: greedy algorithms
 */
 
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int N, P;
pii arr[100001];

int main() {
    
    scanf("%d%d", &N, &P);
    int total = 0, planets = 0;
    for (int i = 1; i <= N; i++) {
        scanf("%d%d", &arr[i].second, &arr[i].first);
        if (i == P) {
            planets++;
            total += arr[i].second;
            arr[i].first = INT_MAX;
        }
    }
    
    sort(arr + 1, arr + N + 1);
    
    for (int i = 1; i < N; i++) {
        if (arr[i].first <= total && arr[i].first <= arr[i].second) {
            total -= arr[i].first;
            total += arr[i].second;
            planets++;
        } else if (arr[i].first > total) {
            break;
        }
    }

    printf("%d\n%d", total, planets);
    
    return 0;
}
