/*
 Solution to ECOO '18 R1 P4 - Fibonacci Spiral by Ava Pun
 Key concepts: implementation, simple math
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<ll, ll> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

ll X, Y, dir;
pii ul, lr;

int main() {
    
    for (int test = 1; test <= 10; test++) {
        
        scanf("%lld%lld", &X, &Y);
        dir = 0;
        ul = {0, 0};
        lr = {1, -1};
        int curr = 1;
        bool found = 0;
        
        while (!found) {
            
            if (X >= ul.f && X <= lr.f && Y <= ul.s && Y >= lr.s) {
                printf("%d\n", curr);
                found = true;
            }
            
            if (dir == 0) {
                ul.f -= abs(ul.s - lr.s);
            } else if (dir == 1) {
                ul.s += abs(ul.f - lr.f);
            } else if (dir == 2) {
                lr.f += abs(ul.s - lr.s);
            } else {
                lr.s -= abs(ul.f - lr.f);
            }
            
            dir++;
            dir %= 4;
            curr++;
        }
    }
    
    return 0;
}
