/*
 Solution to Bank Notes by Ava Pun
 Key concepts: multi knapsack dynamic programming
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
const int MAX = 5005;

int N, K;
int v[205], n[205];
int dp[205][20005];
int trace[205][20005];
deque<pii> dq;
stack<int> st;

int main() {
    
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &v[i]);
    }
    for (int i = 1; i <= N; i++) {
        scanf("%d", &n[i]);
    }
    scanf("%d", &K);
    
    dp[0][0] = 0;
    for (int j = 1; j <= K; j++) {
        dp[0][j] = INF;
    }
    for (int i = 1; i <= N; i++) {
        for (int b = 0; b < v[i]; b++) {
            dq.clear();
            for (int a = 0; a * v[i] + b <= K; a++) {
                int j = a * v[i] + b;
                while (!dq.empty() && dq.front().s < a - n[i]) {
                    dq.pop_front();
                }                
                int nxt = dp[i - 1][j] - a;
                while (!dq.empty() && dq.back().f > nxt) {
                    dq.pop_back();
                }
                dq.push_back({nxt, a});
                dp[i][j] = dq.front().f + a;
                trace[i][j] = a - dq.front().s;
            }
        }
    }
    
    printf("%d\n", dp[N][K]);
    int prev = K;
    for (int i = N; i >= 1; i--) {
        st.push(trace[i][prev]);
        prev -= trace[i][prev] * v[i];
    }
    while (!st.empty()) {
        printf("%d ", st.top());
        st.pop();
    }
    printf("\n");
    
    return 0;
}
