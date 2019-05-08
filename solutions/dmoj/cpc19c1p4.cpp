/*
 Solution to CPC '19 Contest 1 P4 - Sorting Practice by Ava Pun
 Key concepts: shell sort
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
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

int N;
int arr[MAX];

inline bool comp(int i, int j) {
    if (i == j) {
        return 0;
    }
    printf("C %d %d\n", i, j);
    fflush(stdout);
    int ret;
    scanf("%d", &ret);
    if (ret == -1) {
        exit(0);
    }
    return ret;
}

inline void doSwap(int i, int j) {
    if (i == j) {
        return;
    }
    printf("S %d %d\n", i, j);
    fflush(stdout);
    int ret;
    scanf("%d", &ret);
    if (ret == -1) {
        exit(0);
    }
}

int main() {
    
    scanf("%d", &N);
    for (int k = (int) log2(N); k >= 1; k--) {
        int gap = (1 << k) - 1;
        for (int i = gap + 1; i <= N; i++) {
            for (int j = i; j >= gap + 1; j -= gap) {
                doSwap(j - gap, j);
                if (!comp(j - gap, j)) {
                    doSwap(j - gap, j);
                    break;
                }
            }
        }
    }
    printf("A\n");
    fflush(stdout);
    
    return 0;
}
