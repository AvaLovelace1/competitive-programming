/*
 Solution to COI '06 #1 Patrik by Ava Pun
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
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const int MAX = 5e5 + 5;

int N;
int arr[MAX];
stack<pii> st;

int main() {
    
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
    }

    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        while (!st.empty() && st.top().f < arr[i]) {
            ans += st.top().s;
            st.pop();
        }
        int cnt = 0;
        while (!st.empty() && st.top().f == arr[i]) {
            ans += st.top().s;
            cnt = st.top().s;
            st.pop();
        }
        if (!st.empty()) {
            ans++;
        }
        st.push({arr[i], cnt + 1});
    }
    printf("%lld\n", ans);

    return 0;
}
