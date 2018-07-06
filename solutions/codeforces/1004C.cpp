/*
 Solution to Sonya and Robots by Ava Pun
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

int N;
int arr[MAX];
map<int, int> s1, s2;

int main() {
    
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
        s1[arr[i]]++;
    }
    
    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        if (s1[arr[i]] <= 1) {
            ans += (ll) s2.size();
        }
        s1[arr[i]]--;
        s2[arr[i]]++;
    }
    printf("%lld\n", ans);
    
    return 0;
}
