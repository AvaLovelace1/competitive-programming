/*
 Solution to DMOPC '15 Contest 6 P5 - A Classic Problem by Ava Pun
 Key concepts: monoqueue
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
const int MAX = 3e6 + 5;

int N, K;
int arr[MAX];
deque<pii> maxQ, minQ;

int main() {
    
    scanf("%d%d", &N, &K);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
    }
    
    ll ans = 0;
    int idx = 1;
    for (int i = 1; i <= N; i++) {
        while (!maxQ.empty() && maxQ.back().f <= arr[i]) {
            maxQ.pop_back();
        }
        maxQ.push_back({arr[i], i});
        while (!minQ.empty() && minQ.back().f >= arr[i]) {
            minQ.pop_back();
        }
        minQ.push_back({arr[i], i});
        while (!minQ.empty() && !maxQ.empty() && maxQ.front().f - minQ.front().f > K) {
            idx = min(maxQ.front().s + 1, minQ.front().s + 1);
            while (!minQ.empty() && minQ.front().s < idx) {
                minQ.pop_front();
            }
            while (!maxQ.empty() && maxQ.front().s < idx) {
                maxQ.pop_front();
            }
        }
        ans += i - idx + 1;
    }
    printf("%lld\n", ans);
    
    return 0;
}
