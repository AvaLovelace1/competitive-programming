/*
 Solution to TLE '17 Contest 7 P3 - Countless Calculator Computations by Ava Pun
 Key concepts: binary search
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

int Q, Y;
ll Z;

bool func(double x) {
    double ans = x;
    for (int i = 2; i <= Y; i++) {
        ans = pow(x, ans);
        if (ans <= 0 || ans >= Z) {
            return 0;
        }
    }
    return 1;
}

int main() {
    
    scanf("%d", &Q);
    
    while (Q--) {
        
        scanf("%d%lld", &Y, &Z);
        
        int start = 0, end = 10e6, mid;
        for (int i = 0; i < 25; i++) {
            mid = (start + end) / 2;
            if (!func(mid / 1e6)) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        
        printf("%lf\n", (start - 1) / 1e6);
    }
    
    return 0;
}
