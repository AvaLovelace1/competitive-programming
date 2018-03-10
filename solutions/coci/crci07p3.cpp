/*
 Solution to COCI '07 Regional #3 Kuhar by Ava Pun
 Key concepts: binary search
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 105;
const int MAX2 = 1000105;

int N, M;
int x[MAX], y[MAX], ss[MAX], ps[MAX], sl[MAX], pl[MAX];

bool check(int n) {
    
    ll cost = 0;
    for (int i = 1; i <= N; i++) {
        int amount = x[i] * n - y[i];
        int best = INF;
        for (int j = 0; j <= amount / ss[i] + 1; j++) {
            best = min(best, (int) (j * ps[i] + ceil((double) (amount - j * ss[i]) / sl[i]) * pl[i]));
        }
        cost += best;
    }

    return cost <= M;
}

int main() {
    
    scanf("%d%d", &N, &M);
    
    for (int i = 1; i <= N; i++) {
        scanf("%d%d%d%d%d%d", &x[i], &y[i], &ss[i], &ps[i], &sl[i], &pl[i]);
    }
    
    int start = 0, end = 100000, mid;
    while (start < end) {
        mid = (start + end) / 2;
        if (!check(mid)) {
            end = mid;
        } else {
            start = mid + 1;
        }
    }

    printf("%d", start - 1);
    
    return 0;
}
