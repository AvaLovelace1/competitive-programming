/*
 Solution to Mock CCC '18 Contest 1 J5/S3 - A Simulation Problem by Ava Pun
 Key concepts: binary search
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, bool> pii;
typedef pair<int, pii> piii;
const int INF = 0x3F3F3F3F;

ll N;

ll func(ll n) {
    return (N - 1 + n) * (N - n);
}

ll binarySearch(ll x) {
    ll start = 0, end = N - 1, mid;
    while (start < end) {
        mid = (start + end) / 2;
        if (func(N - mid) >= x) {
            end = mid;
        } else {
            start = mid + 1;
        }
    }
    return start;
}

int main() {
    
    scanf("%lld", &N);
    printf("%lld\n", binarySearch(N * (N - 1) / 2));
    
    return 0;
}
