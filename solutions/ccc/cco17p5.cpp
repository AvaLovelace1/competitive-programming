/*
 Solution to CCO '17 P5 - Professional Network by Ava Pun
 Key concepts: greedy algorithms
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

typedef pair<int, int> pii;
const int MAX = 2e5 + 5;

int N0, N;
pii arr[MAX];
priority_queue<int, vector<int>, greater<int>> pq;

inline bool comp(pii a, pii b) {
    return a.f == b.f ? a.s < b.s : a.f > b.f;
}

int main() {

    scanf("%d", &N0);
    int cnt = 0;
    int a, b;
    for (int i = 1; i <= N0; i++) {
        scanf("%d%d", &a, &b);
        if (a == 0 || b == 0) {
            cnt++;
        } else {
            arr[++N] = {a, b};
        }
    }
    sort(arr + 1, arr + N + 1, comp);

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        pq.push(arr[i].s);
        if (cnt + N - i < arr[i].f) {
            ans += pq.top();
            pq.pop();
            cnt++;
        }
    }
    printf("%d\n", ans);

    return 0;
}
