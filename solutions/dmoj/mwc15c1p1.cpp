/*
 Solution to MWC '15 #1 P1: Playlist Panic by Ava Pun
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
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 1005;

int N, X, Y;
int arr[MAX];

int main() {
    
    scanf("%d", &N);
    int a, b;
    for (int i = 1; i <= N; i++) {
        scanf("%d%d", &a, &b);
        arr[i] = b + 60 * a;
    }
    scanf("%d%d", &X, &Y);
    Y += 60 * X;
    sort(arr + 1, arr + N + 1);
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        Y -= arr[i];
        if (Y >= 0) {
            ans++;
        } else {
            break;
        }
    }
    printf("%d\n", ans);
    
    return 0;
}
