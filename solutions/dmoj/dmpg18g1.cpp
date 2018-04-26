/*
 Solution to DMPG '18 G1 - Musical Chairs by Ava Pun
 Key concepts: stack
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

int N, K;
vii v;
stack<pii> st;

bool comp(pii a, pii b) {
    if (a.f == b.f) {
        return a > b;
    } else {
        return b > a;
    }
}

int main() {

    scanf("%d%d", &N, &K);
    int n;
    for (int i = 1; i <= K; i++) {
        scanf("%d", &n);
        v.pb({n, 0});
    }
    for (int i = 1; i <= K + 1; i++) {
        scanf("%d", &n);
        v.pb({n, i});
    }
    sort(v.begin(), v.end(), comp);
    for (pii p : v) {
        if (!st.empty()) {
            if (st.top().s == 0 || p.s != 0) {
                st.push(p);
            } else {
                st.pop();
            }
        } else {
            st.push(p);
        }
    }
    
    n = 0;
    while (!st.empty() && st.top().s != 0) {
        n = st.top().s;
        st.pop();
    }
    printf("%d\n", n);
    
    return 0;
}
