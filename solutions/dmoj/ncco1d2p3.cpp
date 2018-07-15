/*
 Solution to Mock CCO '18 Contest 1 Problem 6 - A Combining Problem by Ava Pun
 Key concepts: greedy algorithms, all nearest larger values
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
const int MAX = 1e6 + 5;

int N;
int arr[MAX], pre[MAX];
stack<int> st;
ll ans = 0;

int main() {
    
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
    }

    st.push(INF);
    for (int i = 1; i <= N; i++) {
        while (st.top() <= arr[i]) {
            st.pop();
        }
        pre[i] = st.top();
        st.push(arr[i]);
    }
    while (st.size() > 1) {
        st.pop();
    }
    
    for (int i = N; i >= 1; i--) {
        while (st.top() < arr[i]) {
            st.pop();
        }
        int nxt = st.top();
        if (nxt != INF || pre[i] != INF) {
            ans += min(nxt, pre[i]);
        }
        st.push(arr[i]);
    }
    printf("%lld\n", ans);
    
    return 0;
}
