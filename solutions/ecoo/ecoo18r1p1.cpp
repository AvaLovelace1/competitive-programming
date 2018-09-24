/*
 Solution to ECOO '18 R1 P1 - Willow's Wild Ride by Ava Pun
 Key concepts: implementation
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
const int MAX = 1e5 + 5;

int T, N;

int main() {
    
    for (int test = 1; test <= 10; test++) {
        scanf("%d%d", &T, &N);
        int cnt = 0;	
        for (int i = 1; i <= N; i++) {
            char c;
            scanf(" %c", &c);
            if (c == 'B') {
                cnt += T;	
            }
            if (cnt > 0) {
                cnt--;
            }
        }
        printf("%d\n", cnt);
    }
    
    return 0;
}
