/*
 Solution to CCC '17 S1 - Sum Game by Ava Pun
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
int arr[MAX][2];

int main() {
    
    scanf("%d", &N);
    int sumA = 0, sumB = 0, ans = 0;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i][0]);
    }
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i][1]);
    }
    for (int i = 1; i <= N; i++) {
        sumA += arr[i][0];
        sumB += arr[i][1];
        if (sumA == sumB) {
            ans = i;
        }
    }
    printf("%d", ans);
    
    return 0;
}
