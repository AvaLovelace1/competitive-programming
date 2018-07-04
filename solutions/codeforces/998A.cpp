/*
 Solution to Balloons by Ava Pun
 Key concepts: implementation
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 5e4 + 5;

int N;
int arr[11];

int main() {
    
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
    }
    
    if (N == 1) {
        printf("-1\n");
    } else if (N == 2) {
        if (arr[1] == arr[2]) {
            printf("-1\n");
        } else {
            printf("1\n1\n");
        }
    } else {
        if (arr[1] != accumulate(arr + 2, arr + N + 1, 0)) {
            printf("1\n1\n");
        } else {
            printf("1\n2\n");
        }
    }
    
    return 0;
}
