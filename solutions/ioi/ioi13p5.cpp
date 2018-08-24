/*
 Solution to IOI '13 P5 - Robots by Ava Pun
 Key concepts: binary search, greedy algorithms
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

int a, b, t;
int maxX[MAX], maxY[MAX], wt[MAX], sz[MAX];
pii arr[MAX];

bool check(int k, int A, int B, int T, int X[], int Y[]) {
    
    priority_queue<int> pq;
    int idx = 0;
    for (int i = 0; i < A; i++) {
        while (idx < T && arr[idx].f < X[i]) {
            pq.push(arr[idx].s);
            idx++;
        }
        int cnt = 0;
        while (!pq.empty() && cnt < k) {
            pq.pop();
            cnt++;
        }
    }
    while (idx < T) {
        pq.push(arr[idx].s);
        idx++;
    }
    
    for (int i = B - 1; i >= 0; i--) {
        int cnt = 0;
        while (!pq.empty() && cnt < k) {
            if (pq.top() >= Y[i]) {
                return 0;
            }
            pq.pop();
            cnt++;
        }
    }
    
    return pq.empty();
}

int putaway(int A, int B, int T, int X[], int Y[], int W[], int S[]) {

    sort(X, X + A), sort(Y, Y + B);
    for (int i = 0; i < T; i++) {
        arr[i] = {W[i], S[i]};
    }
    sort(arr, arr + T);
    
    int lo = 1, hi = T + 1, mid;
    while (lo < hi) {
        mid = (lo + hi) / 2;
        if (check(mid, A, B, T, X, Y)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return lo == T + 1 ? -1 : lo;
}

int main() {
    
    scanf("%d%d%d", &a, &b, &t);
    for (int i = 0; i < a; i++) {
        scanf("%d", &maxX[i]);
    }
    for (int i = 0; i < b; i++) {
        scanf("%d", &maxY[i]);
    }
    for (int i = 0; i < t; i++) {
        scanf("%d%d", &wt[i], &sz[i]);
    }
    printf("%d\n", putaway(a, b, t, maxX, maxY, wt, sz));
    
    return 0;
}
