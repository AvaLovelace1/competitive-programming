/*
 Solution to CCC '18 S1 - Voronoi Villages by Ava Pun
 Key concepts: implementation
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

int N;
int arr[105];

int main() {
    
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    
    sort(arr, arr + N);
    double ans = INF;
    for (int i = 1; i < N - 1; i++) {
        ans = min(ans, (arr[i + 1] - arr[i]) / 2.0 + (arr[i] - arr[i - 1]) / 2.0);
    }
    
    printf("%.1lf", ans);
    
    return 0;
}
