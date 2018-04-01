/*
 Solution to TLE '17 Contest 7 P1 - Stargazing by Ava Pun
 Key concepts: implementation, set
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
const int MAX = 1005;

int N;
pii arr[MAX];
set<pii> ss;

int main() {

    scanf("%d", &N);
    int p, x, y;
    for (int i = 2; i <= N; i++) {
        scanf("%d%d%d", &p, &x, &y);
        arr[i] = {arr[p].f + x, arr[p].s + y};
    }
    
    for (int i = 1; i <= N; i++) {
        ss.insert(arr[i]);
    }
    
    printf("%ld\n", ss.size());
    
    return 0;
}
