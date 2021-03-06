/*
 Solution to The Phone Number by Ava Pun
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
typedef pair<pii, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

int N;

int main() {
    
    scanf("%d", &N);
    int root = round(sqrt(N));
    int prev = 0;
    for (int i = root; i <= N; i += root) {
        for (int j = i; j > prev; j--) {
            printf("%d ", j);
        }
        prev = i;
        if (i != N && i + root > N) {
            i = N - root;
        }
    }
    printf("\n");
    
    return 0;
}
