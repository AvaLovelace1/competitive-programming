/*
 Solution to Weakened Common Divisor by Ava Pun
 Key concepts: brute force, number theory
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
const int MOD = 998244353;
const int MAX = 150000 + 5;

int N;
pii arr[MAX];
set<int> ss;

inline bool prime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

inline void fact(int n) {
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (prime(i)) {
                ss.insert(i);
            }
            if (prime(n / i)) {
                ss.insert(n / i);
            }
        }
    }
    ss.erase(1);
}

int main() {
    
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d%d", &arr[i].f, &arr[i].s);
    }
    fact(arr[1].f), fact(arr[1].s);
    
    for (int i : ss) {
        bool good = 1;
        for (int j = 1; j <= N; j++) {
            good &= arr[j].f % i == 0 || arr[j].s % i == 0;
            if (!good) {
                break;
            }
        }
        if (good) {
            printf("%d\n", i);
            return 0;
        }
    }
    printf("-1\n");
    
    return 0;
}
