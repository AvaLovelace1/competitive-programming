/*
 Solution to Mike and Children by Ava Pun
 Key concepts: brute force
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

int N;
int arr[1005];
int idx[200005];

int main() {
    
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            idx[arr[i] + arr[j]]++;
        }
    }
    int ans = 0;
    for (int i = 1; i <= 200000; i++) {
        ans = max(ans, idx[i]);
    }
    printf("%d\n", ans);
    
    return 0;
}
