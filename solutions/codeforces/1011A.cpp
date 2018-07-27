/*
 Solution to Stages by Ava Pun
 Key concepts: implementation, greedy algorithms
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

int N, K;
char arr[55];

int main() {
    
    scanf("%d%d", &N, &K);
    scanf("%s", arr);
    sort(arr, arr + N);
    char prev = 'a' - 2;
    int ans = 0;
    for (int i = 0; i < N && K; i++) {
        if (arr[i] >= prev + 2) {
            ans += arr[i] - 'a' + 1;
            prev = arr[i];
            K--;
        }
    }
    if (K != 0) {
        printf("-1\n");
    } else {
        printf("%d\n", ans);
    }
    
    return 0;
}
