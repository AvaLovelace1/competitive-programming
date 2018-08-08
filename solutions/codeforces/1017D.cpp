/*
 Solution to The Wu by Ava Pun
 Key concepts: brute force
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
const int MAX = 5e5 + 5;

int N, M, Q;
int arr[15], strs[4100];
int val[4100][4100], pref[4100][105];
char str[15];
vi ss;

inline int conv() {
    int n = 0;
    for (int j = 0; j < N; j++) {
        n <<= 1;
        n |= str[j] == '1';
    }
    return n;
}

int main() {
    
    scanf("%d%d%d", &N, &M, &Q);
    for (int i = N - 1; i >= 0; i--) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < M; i++) {
        scanf("%s", str);
        strs[conv()]++;
    }
    
    for (int i = 0; i < (1 << N); i++) {
        for (int j = i; j < (1 << N); j++) {
            int v = ~(i ^ j);
            for (int k = 0; k < N; k++) {
                if (v & (1 << k)) {
                    val[i][j] += arr[k];
                }
            }
        }
        if (strs[i]) {
            ss.pb(i);
        }
    }
    
    for (int i = 0; i < (1 << N); i++) {
        for (int j : ss) {
            int i0 = min(i, j), j0 = max(i, j);
            if (val[i0][j0] <= 100) {
                pref[i][val[i0][j0]] += strs[j];
            }
        }
        for (int j = 1; j <= 100; j++) {
            pref[i][j] += pref[i][j - 1];
        }
    }
    
    while (Q--) {
        int k;
        scanf("%s%d", str, &k);
        printf("%d\n", pref[conv()][k]);
    }
    
    return 0;
}
