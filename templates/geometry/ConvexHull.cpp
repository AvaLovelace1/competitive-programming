/*
 ~ Andrew's Monotone Chain Algorithm for Convex Hull ~
 
 Finds the convex hull of a set of points. Much easier than Graham Scan IMO.
 
 Time complexity: O(NlogN)
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

int N;
pii arr[MAX];
stack<pii> h1, h2;

int orientation(pii a, pii b, pii c) {
    return (b.second - a.second) * (c.first - b.first) - (c.second - b.second) * (b.first - a.first);
}

void popStack(stack<pii> &st) {
    while (st.size() > 1) {
        printf("(%d, %d) ", st.top().first, st.top().second);
        st.pop();
    }
}

void process(pii p, stack<pii> &st) {
    bool cw = false;
    while (st.size() > 1 && !cw) {
        pii b = st.top();
        st.pop();
        pii a = st.top();
        if (orientation(a, b, p) > 0) {
            cw = true;
            st.push(b);
        }
    }
    st.push(p);
}

void hull() {
    sort(arr, arr + N);
    for (int i = 0; i < N; i++) {
        process(arr[i], h1);
    }
    for (int i = N - 1; i >= 0; i--) {
        process(arr[i], h2);
    }
}

int main() {
    
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d%d", &arr[i].first, &arr[i].second);
    }
    hull();
    
    printf("Points on convex hull: ");
    popStack(h1);
    popStack(h2);
    printf("\n");
    
    return 0;
    
}
