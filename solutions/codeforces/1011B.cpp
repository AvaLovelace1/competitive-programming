/*
 Solution to Planning The Expedition by Ava Pun
 Key concepts: implementation, brute force
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<pii, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

int N, M;
int arr[105];

int main() {
    
    scanf("%d%d", &N, &M);
    int n;
    for (int i = 1; i <= M; i++) {
        scanf("%d", &n);
        arr[n]++;
    }
    for (int i = 100; i > 0; i--) {
        int cnt = 0;
        for (int j = 1; j <= 100; j++) {
            cnt += arr[j] / i;
        }
        if (cnt >= N) {
            printf("%d\n", i);
            return 0;
        }
    }
    printf("0\n");
    
    return 0;
}
