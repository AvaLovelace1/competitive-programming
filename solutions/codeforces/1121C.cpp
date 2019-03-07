/*
 Solution to System Testing by Ava Pun
 Key concepts: simulation
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
const ll INFL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

int N, K;
int arr[1005];
queue<pii> q;
int done = 0;
pii cnt[105];
bool interest[1005];

int main() {
    
    scanf("%d%d", &N, &K);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
        q.push({0, i});
    }
    
    while (done != N) {
        for (int i = 1; i <= K; i++) {
            if (cnt[i].f == arr[cnt[i].s]) {
                if (cnt[i].s != 0) {
                    done++;
                }
                if (!q.empty()) {
                    cnt[i] = q.front();
                    q.pop();
                } else {
                    cnt[i] = {0, 0};
                }
            }
            if (cnt[i].s != 0) {
                cnt[i].f++;
            }
        }
        int S = (int) round((double) done / N * 100);
        for (int i = 1; i <= K; i++) {
            if (cnt[i].f == S && cnt[i].s != 0) {
                interest[cnt[i].s] = 1;
            }
        }
    }
    
    printf("%d\n", accumulate(interest, interest + N + 1, 0));
    
    return 0;
}
