/*
 Solution to The Supersonic Rocket by Ava Pun
 Key concepts: convex hull, KMP
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<pii, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

int N, M;
pii pts1[MAX], pts2[MAX];
stack<pii> h1, h2;
vector<double> hull1, hull2;
int lps[2 * MAX];

inline ll orientation(pii a, pii b, pii c) {
    return (ll) (b.s - a.s) * (c.f - b.f) - (ll) (c.s - b.s) * (b.f - a.f);
}

inline double dist(pii p1, pii p2){
    ll x = p1.f - p2.f, y = p1.s - p2.s;
    return sqrt(x * x + y * y);
}

inline double angle(pii p1, pii p2, pii p3){
    ll x1 = p1.f - p2.f, y1 = p1.s - p2.s;
    ll x2 = p3.f - p2.f, y2 = p3.s - p2.s;
    ll dot = x1 * x2 + y1 * y2, det = x1 * y2 - y1 * x2;
    double d1 = dist(p1, p2), d2 = dist(p2, p3);
    return atan2(det, dot) * (d1 / d2);
}

inline void popStack(stack<pii> &st, vii &hull) {
    while (st.size() > 1) {
        hull.pb({st.top().f, st.top().s});
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

void findHull(int N, pii arr[], vector<double> &hull) {
    vii v;
    while (!h1.empty()) {
        h1.pop();
    }
    while (!h2.empty()) {
        h2.pop();
    }
    sort(arr, arr + N);
    for (int i = 0; i < N; i++) {
        process(arr[i], h1);
    }
    for (int i = N - 1; i >= 0; i--) {
        process(arr[i], h2);
    }
    popStack(h1, v);
    popStack(h2, v);
    for (int i = 0; i < v.size(); i++) {
        pii p1 = v[i], p2 = v[(i + 1) % v.size()], p3 = v[(i + 2) % v.size()];
        hull.pb(dist(p1, p2));
        hull.pb(angle(p1, p2, p3));
    }
}

bool kmp(vector<double> &T, vector<double> &S) {
    int N = (int) S.size(), M = (int) T.size();
    int len = 0;
    lps[0] = 0; 
    int i = 1, j = 0;
    while (i < M) {
        if (abs(T[i] - T[len]) < 1e-9) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    i = 0, j = 0;
    while (i < N) {
        if (abs(T[j] - S[i]) < 1e-9) {
            j++, i++;
        }
        if (j == M) {
            return 1;
        } else if (i < N && abs(T[j] - S[i]) > 1e-9) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return 0;
}

int main() {
    
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++) {
        scanf("%d%d", &pts1[i].f, &pts1[i].s);
    }
    for (int i = 0; i < M; i++) {
        scanf("%d%d", &pts2[i].f, &pts2[i].s);
    }
    findHull(N, pts1, hull1);
    findHull(M, pts2, hull2);
    
    if (hull1.size() != hull2.size()) {
        printf("NO\n");
    } else {
        int n = (int) hull1.size();
        for (int i = 0; i < n; i++) {
            hull1.pb(hull1[i]);
        }
        printf(kmp(hull2, hull1) ? "YES\n" : "NO\n");
    }
    
    return 0;
}
