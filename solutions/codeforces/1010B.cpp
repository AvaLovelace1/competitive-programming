/*
 Solution to Rocket by Ava Pun
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
typedef pair<pii, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 1005;

int M, N;
int arr[35];

inline int ask(int y) {
    int ans;
    printf("%d\n", y);
    fflush(stdout);
    scanf("%d", &ans);
    return ans;
}

int main() {
    
    scanf("%d%d", &M, &N);
    for (int i = 1; i <= N; i++) {
        int a = ask(1);
        if (a == 1 || a == -1) {
            arr[i] = a;
        } else {
            return 0;
        }
    }
    
    int idx = 1;
    int lo = 1, hi = M, mid;
    while (lo < hi) {
        mid = (lo + hi) / 2;
        int a = ask(mid);
        if (a == 0 || a == -2) {
            return 0;
        } else if (a * arr[idx] == -1) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
        idx = (idx % N + 1);
    }
    ask(lo);
    
    return 0;
}
