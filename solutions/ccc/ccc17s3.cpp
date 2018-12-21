/*
 Solution to CCC '17 S3 - Nailed It! by Ava Pun
 Key concepts: simple math
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 2000;

int N;
int arr[MAX + 5], heights[2 * MAX + 5];

int main() {
    
    scanf("%d", &N);
    int n;
    for (int i = 0; i < N; i++) {
        scanf("%d", &n);
        arr[n]++;
    }

    for (int i = 1; i <= MAX; i++) {
        for (int j = i; j <= MAX; j++) {
            if (i == j) {
                heights[i + j] += arr[i] / 2;
            } else {
                heights[i + j] += min(arr[i], arr[j]);
            }
        }
    }
    
    int maxN = 1, maxCnt = 0;
    for (int i = 1; i <= 2 * MAX; i++) {
        if (heights[i] > maxN) {
            maxN = heights[i];
            maxCnt = 1;
        } else if (heights[i] == maxN) {
            maxCnt++;
        }
    }
    
    printf("%d %d", maxN, maxCnt);
    
    return 0;
}
