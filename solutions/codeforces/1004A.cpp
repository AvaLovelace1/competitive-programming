/*
 Solution to Sonya and Hotels by Ava Pun
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
const int MAX = 1e5 + 5;

int N, D;
int arr[105];

int main() {
    
    scanf("%d%d", &N, &D);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
    }
    int ans = 2;
    for (int i = 2; i <= N; i++) {
        int diff = arr[i] - arr[i - 1];
        if (diff > 2 * D) {
            ans += 2;
        } else if (diff == 2 * D) {
            ans++;
        }
    }
    printf("%d\n", ans);
    
    return 0;
}
