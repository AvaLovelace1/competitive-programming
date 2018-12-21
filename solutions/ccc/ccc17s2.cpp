/*
 Solution to CCC '17 S2 - High Tide, Low Tide by Ava Pun
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
    
    if (N % 2 == 0) {
        for (int i = 0; i < N / 2; i++) {
            printf("%d %d ", arr[N / 2 - 1 - i], arr[N / 2 + i]);
        }
    } else {
        for (int i = 0; i < N / 2; i++) {
            printf("%d %d ", arr[N / 2 - i], arr[N / 2 + i + 1]);
        }
        printf("%d", arr[0]);
    }
    
    return 0;
}
