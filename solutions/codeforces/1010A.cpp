/*
 Solution to Fly by Ava Pun
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
typedef pair<pii, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 1000 + 5;

int N, M;
int lift[MAX], land[MAX];

int main() {
    
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &lift[i]);
    }
    for (int i = 1; i <= N; i++) {
        scanf("%d", &land[i]);
    }
    double w = M;
    for (int i = N; i >= 1; i--) {
        if (lift[i] == 1 || land[i % N + 1] == 1) {
            printf("-1\n");
            return 0;
        }
        w += w / (land[i % N + 1] - 1);
        w += w / (lift[i] - 1);
    }
    printf("%.10lf\n", w - M);
    
    return 0;
}
