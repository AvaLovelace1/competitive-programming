/*
 Solution to Bracket Subsequence by Ava Pun
 Key concepts: greedy algorithms
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

int N, K;
char arr[MAX];

int main() {

    scanf("%d%d", &N, &K);
    scanf("%s", arr);
    
    int i = 0;
    int len = 0, cnt = 0;
    for (i = 0; i < N; i++) {
        if (arr[i] == '(') {
            cnt++;
        } else {
            cnt--;
        }
        len++;
        if (len + cnt == K) {
            break;
        }
    }
    for (int j = 0; j <= i; j++) {
        printf("%c", arr[j]);
    }
    for (int j = 1; j <= cnt; j++) {
        printf(")");
    }
    printf("\n");
    
    return 0;
}
