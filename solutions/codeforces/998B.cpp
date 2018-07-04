/*
 Solution to Cutting by Ava Pun
 Key concepts: greedy algorithms
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

int N, B;
int arr[105];
vi cuts;

int main() {
    
    scanf("%d%d", &N, &B);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
    }
    
    int cnt = (arr[1] & 1) ? 1 : -1;
    for (int i = 2; i <= N; i++) {
        if (cnt == 0) {
            cuts.pb(abs(arr[i] - arr[i - 1]));
        }
        cnt += (arr[i] & 1) ? 1 : -1;
    }
    sort(cuts.begin(), cuts.end());
    
    int ans = 0;
    for (int i : cuts) {
        if (i <= B) {
            ans++;
            B -= i;
        } else {
            break;
        }
    }
    printf("%d\n", ans);
    
    return 0;
}
