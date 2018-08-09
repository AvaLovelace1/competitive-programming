/*
 Solution to CCO '13 P1 - All Your Base Belong to Palindromes by Ava Pun
 Key concepts: math
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

int X;
vi ans;

inline bool palin() {
    for (int i = 0; i < ans.size() / 2; i++) {
        if (ans[i] != ans[ans.size() - i - 1]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    
    scanf("%d", &X);
    for (int i = 2; i * i <= X; i++) {
        ans.clear();
        int n = X;
        while (n) {
            ans.pb(n % i);
            n /= i;
        }
        if (palin()) {
            printf("%d\n", i);
        }
    }
    for (int i = sqrt(X); i >= 1; i--) {
        if ((X - i) % i == 0 && (X - i) / i > i) {
            printf("%d\n", (X - i) / i);
        }
    }
    
    return 0;
}
