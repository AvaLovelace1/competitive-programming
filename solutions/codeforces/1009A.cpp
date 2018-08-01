/*
 Solution to Game Shopping by Ava Pun
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
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 1000 + 5;

int N, M;
int c[MAX];
queue<int> q;

int main() {
    
    scanf("%d%d", &N, &M);
    int n;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &c[i]);
    }
    for (int i = 1; i <= M; i++) {
        scanf("%d", &n);
        q.push(n);
    }
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (!q.empty() && q.front() >= c[i]) {
            q.pop();
            ans++;
        }
    }
    printf("%d\n", ans);
    
    return 0;
}
