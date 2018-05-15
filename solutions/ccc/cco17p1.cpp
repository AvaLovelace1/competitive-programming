/*
 Solution to CCO '17 P1 - Vera and Trail Building by Ava Pun
 Key concepts: graph theory, greedy algorithms
 */

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a));

typedef vector<int> vi;
const int INF = 0x3F3F3F3F;
const int MAX = 10005;

int K;
vi ans;

int main() {

    scanf("%d", &K);
    while (K) {
        int n = 1;
        while (n * (n - 1) / 2 <= K) {
            n++;
        }
        n--;
        ans.pb(n);
        K -= n * (n - 1) / 2;
    }

    int N = accumulate(ans.begin(), ans.end(), 0);
    printf("%d %d\n", N, N + ans.size() - 1);
    int curr = 1;

    for (int i = 0; i < ans.size(); i++) {
        int k = ans[i];
        for (int j = curr; j < curr + k - 1; j++) {
            printf("%d %d\n", j, j + 1);
        }
        printf("%d %d\n", curr + k - 1, curr);
        if (i != ans.size() - 1) {
            printf("%d %d\n", curr + k - 1, curr + k);
        }
        curr += k;
    }

    return 0;
}
