/*
 Solution to ECOO '18 R1 P2 - Rue's Rings by Ava Pun
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
const int MAX = 705;

int N;
set<int> arr[MAX];
int id[MAX];
vi ans;

int main() {
    
    for (int test = 1; test <= 10; test++) {
        
        ans.clear();
        scanf("%d", &N);
        for (int i = 1; i <= N; i++) {
            arr[i].clear();
        }
        
        int n, x;
        int minN = INF;
        for (int i = 1; i <= N; i++) {
            scanf("%d%d", &id[i], &n);
            while (n--) {
                scanf("%d", &x);
                arr[i].insert(x);
                minN = min(minN, x);
            }
        }
        for (int i = 1; i <= N; i++) {
            if (arr[i].find(minN) != arr[i].end()) {
                ans.pb(id[i]);
            }
        }
        
        sort(ans.begin(), ans.end());
        printf("%d {", minN);
        for (int i = 0; i < ans.size(); i++) {
            printf("%d", ans[i]);
            if (i != ans.size() - 1) {
                printf(",");
            }
        }
        printf("}\n");
    }
    
    return 0;
}
