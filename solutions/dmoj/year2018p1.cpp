/*
 Solution to Happy New Year! by Ava Pun
 Key concepts: implementation
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll H, M, S;
ll seconds;

int main() {
    
    scanf("%lld%lld%lld", &H, &M, &S);
    seconds = 0;
    seconds += S;
    seconds += M * 60;
    seconds += H * 3600;
    
    ll h, m, s;
    h = 11 - (seconds / 3600 % 12);
    seconds %= 3600;
    m = 59 - (seconds / 60);
    seconds %= 60;
    s = 60 - seconds;
    
    if (s >= 60) {
        m += s / 60;
        s %= 60;
    }
    if (m >= 60) {
        h += m / 60;
        m %= 60;
    }
    if (h >= 12) {
        h %= 12;
        if (h == 0) {
            h = 12;
        }
    }
    
    if (h <= 9) {
        printf("0");
    }
    printf("%lld:", h);
    if (m <= 9) {
        printf("0");
    }
    printf("%lld:", m);
    if (s <= 9) {
        printf("0");
    }
    printf("%lld", s);
    
    return 0;
}
