/*
 Solution to ECOO '18 R2 P2 - Homework by Ava Pun
 Key concepts: priority queue, greedy algorithms
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
const int INF = 0x3F3F3F3F;
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

int N;
vector<double> arr[MAX];

int main() {
    
    for (int test = 1; test <= 10; test++) {
        for (int i = 1; i <= 1e6; i++) {
            arr[i].clear();
        }
        scanf("%d", &N);
        int a;
        double b;
        for (int i = 1; i <= N; i++) {
            scanf("%d%lf", &a, &b);
            arr[a].pb(b);
        }
        priority_queue<double> pq;
        double ans = 0;
        for (int i = 1e6; i >= 1; i--) {
            for (auto j : arr[i]) {
                pq.push(j);
            }
            if (!pq.empty()) {
                ans += pq.top();
                pq.pop();
            }
        }
        printf("%.4lf\n", ans);
    }
    
    return 0;
}
