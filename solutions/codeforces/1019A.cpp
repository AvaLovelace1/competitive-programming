/*
 Solution to Elections by Ava Pun
 Key concepts: brute force, greedy algorithms
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
const int MAX = 3000 + 5;

int N, M;
int p[MAX], c[MAX];
vii arr[MAX];
set<pii> ss;

int main() {
    
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++) {
        scanf("%d%d", &p[i], &c[i]);
        arr[p[i]].pb({c[i], i});
        if (p[i] != 1) {
            ss.insert({c[i], i});
        }
    }
    for (int i = 2; i <= M; i++) {
        sort(arr[i].begin(), arr[i].end(), greater<pii>());
    }
    
    ll ans = INFL, currSum = 0, curr = 0;
    int currVotesSum = (int) arr[1].size(), currVotes = 0;
    for (int i = N / 2 + 1; i >= 0; i--) {
        for (int j = 2; j <= M; j++) {
            while (arr[j].size() > i) {
                currSum += arr[j][arr[j].size() - 1].f;
                currVotesSum++;
                ss.erase(arr[j][arr[j].size() - 1]);
                arr[j].pop_back();
            }
        }
        curr = currSum;
        currVotes = currVotesSum;
        for (pii p : ss) {
            if (currVotes > i) {
                break;
            }
            curr += p.f;
            currVotes++;
        }
        if (currVotes > i) {
            ans = min(ans, curr);
        }
    }
    printf("%lld\n", ans);
    
    return 0;
}
