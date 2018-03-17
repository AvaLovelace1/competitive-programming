/*
 Solution to COCI '08 Contest 6 #4 Cuskija by Ava Pun
 Key concepts: ad hoc, brute force
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
const int MOD = 1e9 + 7;
const int MAX = 10005;

int N;
int mod[3][MAX];
int cnt[3], closed[3] = {0, 2, 1}, curr[3];
vi ans;

bool solve(int prev) {
    if (ans.size() == N) {
        return true;
    }
    for (int i = 0; i < 3; i++) {
        if (prev == -1 || closed[prev] != i) {
            if (cnt[i]) {
                ans.pb(i);
                cnt[i]--;
                if (solve(i)) {
                    return true;
                }
                ans.pop_back();
                cnt[i]++;
            }
        }
    }
    return false;
}

int main() {
    
    scanf("%d", &N);
    int n;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &n);
        mod[n % 3][cnt[n % 3]++] = n;
    }
    
    if (!solve(-1)) {
        printf("impossible\n");
    } else {
        for (int i : ans) {
            printf("%d ", mod[i][curr[i]++]);
        }
        printf("\n");
    }
    
    return 0;
}
