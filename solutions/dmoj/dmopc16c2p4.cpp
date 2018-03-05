/*
 Solution to DMOPC '16 Contest 2 P4 - Zeros by Ava Pun
 Key concepts: binary search, mathematics
 */
 
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int A, B;

ll findZeroes(ll x) {
    ll sum = 0;
    for (ll i = 5; i <= x; i *= 5) {
        sum += x / i;
    }
    return sum;
}

ll binSearch(int x) {
    ll start = 1, end = 5e9, mid;
    while (start < end) {
        mid = (start + end) / 2;
        if (findZeroes(mid) >= x) {
            end = mid;
        } else {
            start = mid + 1;
        }
    }
    return start;
}

int main() {
    
    scanf("%d%d", &A, &B);
    printf("%lld", binSearch(B + 1) - binSearch(A));

    return 0;
}
