/*
 Solution to Technogoblet of Fire by Ava Pun
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
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

int N, M, K;
int arr[105], arr2[105];
int chosen[105];
vii school[105];

int main() {
    
    scanf("%d%d%d", &N, &M, &K);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr2[i]);
        school[arr2[i]].pb({arr[i], i});
    }
    for (int i = 1; i <= M; i++) {
        sort(school[i].begin(), school[i].end(), greater<pii>());
    }
    int ans = 0;
    for (int i = 1; i <= K; i++) {
        scanf("%d", &chosen[i]);
        ans += school[arr2[chosen[i]]][0].s != chosen[i];
    }
    printf("%d\n", ans);
    
    return 0;
}
