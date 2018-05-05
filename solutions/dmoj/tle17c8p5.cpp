/*
 Solution to TLE '17 Contest 8 P5 - Battle Plan 2 by Ava Pun
 Key concepts: sparse table
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
const int MAX = 2e5 + 5;
const int MAXQ = 1e5 + 5;
const int MAXL = 18;

int N, K, Q;
int arr[MAX], fight[MAX];
int sp[MAXL + 1][MAX];
piii quers[MAXQ];
int ans[MAXQ];

int main() {
    
    scanf("%d%d%d", &N, &K, &Q);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 1; i <= K; i++) {
        scanf("%d", &fight[i]);
    }
    for (int i = 1; i <= Q; i++) {
        scanf("%d%d%d", &quers[i].f.f, &quers[i].s.f, &quers[i].s.s);
        quers[i].f.s = i;
    }
    sort(quers + 1, quers + Q + 1);
    
    int prev = -1;
    for (int i = 1; i <= Q; i++) {
        int ft = quers[i].f.f, pos = quers[i].f.s, l = quers[i].s.f, r = quers[i].s.s;
        if (ft != prev) {
            prev = ft;
            for (int j = 0; j <= MAXL; j++) {
                for (int k = 0; k < MAX; k++) {
                    sp[j][k] = N + 1;
                }
            }
            int idx = N + 1, sum = 0;
            for (int j = N; j > 0; j--) {
                sum += arr[j];
                while (sum > fight[ft]) {
                    idx--;
                    sum -= arr[idx];
                }
                sp[0][j] = idx;
            }
            for (int j = 1; j <= MAXL; j++) {
                for (int k = 1; k <= N; k++) {
                    sp[j][k] = sp[j - 1][sp[j - 1][k]];
                }
            }
        }
        int j = MAXL;
        if (sp[j][l] <= r) {
            ans[pos] = -1;
        } else {
            ans[pos] = 1;
            while (j >= 0) {
                if (sp[j][l] <= r) {
                    ans[pos] += 1 << j;
                    l = sp[j][l];
                } else {
                    j--;
                }
            }
        }
    }
    
    for (int i = 1; i <= Q; i++) {
        printf("%d\n", ans[i]);
    }
    
    return 0;
}
