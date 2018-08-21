/*
 Solution to Down or Right by Ava Pun
 Key concepts: ad hoc
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
const int MAX = 2e5 + 5;

int N;
vector<char> ans[2];
char arr[3];

inline bool query(int r1, int c1, int r2, int c2) {
    printf("? %d %d %d %d\n", r1, c1, r2, c2);
    fflush(stdout);
    scanf("%s", arr);
    if (arr[0] == 'Y') {
        return 1;
    } else if (arr[0] == 'N') {
        return 0;
    } else {
        exit(0);
    }
}

int main() {

    scanf("%d", &N);
    int i = 1, j = 1;
    while (i + j < N + 1) {
        if (query(i + 1, j, N, N)) {
            ans[0].pb('D');
            i++;
        } else {
            ans[0].pb('R');
            j++;
        }
    }
    i = N, j = N;
    while (i + j > N + 1) {
        if (query(1, 1, i, j - 1)) {
            ans[1].pb('R');
            j--;
        } else {
            ans[1].pb('D');
            i--;
        }
    }
    
    printf("! ");
    for (char c : ans[0]) {
        printf("%c", c);
    }
    for (int i = (int) ans[1].size() - 1; i >= 0; i--) {
        printf("%c", ans[1][i]);
    }
    printf("\n");
    fflush(stdout);
    
    return 0;
}
