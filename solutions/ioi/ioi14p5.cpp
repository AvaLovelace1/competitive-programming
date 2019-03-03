/*
 Solution to IOI '14 P5 - Friend by Ava Pun
 Key concepts: graph theory, dynamic programming
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
const int MAX = 2e5 + 5;

int findSample(int n, int confidence[], int host[], int protocol[]) {
    int ans = 0;
    // dismantle the graph operation by operation, condensing the nodes
    // into their hosts
    for (int i = n - 1; i > 0; i--) {
        if (protocol[i] == 0) {
            // if i is taken, host[i] cannot be taken
            ans += confidence[i];
            confidence[host[i]] = max(0, confidence[host[i]] - confidence[i]); 
        } else if (protocol[i] == 1) {
            // if you take host[i], you should also take i
            confidence[host[i]] += confidence[i];
        } else {
            // you cannot take both i and host[i]
            confidence[host[i]] = max(confidence[host[i]], confidence[i]);
        }
    }
    return ans + confidence[0];
}
