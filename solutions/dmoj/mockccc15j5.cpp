/*
 Solution to Royal Guard by Ava Pun
 Key concepts: binary search
 */

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int N, M;
pii x[100001], y[100001];

int main() {

    scanf("%d", &N);
    int a, b;
    for (int i = 0; i < N; i++) {
        scanf("%d%d", &a, &b);
        x[i] = {a, b};
        y[i] = {b, a};
    }
    
    sort(x, x + N);
    sort(y, y + N);
    
    scanf("%d", &M);
    
    long long int total = 0;
    M--;
    int a0, b0;
    pii lower, upper;
    scanf("%d%d", &a0, &b0);
    while (M--) {
        scanf("%d%d", &a, &b);
        if (a == a0) {
            lower = {a, min(b, b0)};
            upper = {a, max(b, b0)};
            auto itr1 = lower_bound(x, x + N, lower);
            auto itr2 = upper_bound(x, x + N, upper);
            total += itr2 - itr1;
        } else {
            lower = {b, min(a, a0)};
            upper = {b, max(a, a0)};
            auto itr1 = lower_bound(y, y + N, lower);
            auto itr2 = upper_bound(y, y + N, upper);
            total += itr2 - itr1;
        }
        a0 = a, b0 = b;
    }
    
    printf("%lld", total);
    
    return 0;
    
}
