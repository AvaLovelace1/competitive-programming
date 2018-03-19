/*
 Solution to DMPG '15 S5 - Black and White by Ava Pun
 Key concepts: 2D difference array
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

int N, M;
bool arr[MAX][MAX];

int main() {
    
    scanf("%d%d", &N, &M);
    int x, y, w, h;
    while (M--) {
        scanf("%d%d%d%d", &x, &y, &w, &h);
        x++, y++;
        arr[x][y] = !arr[x][y];
        arr[x][y + h] = !arr[x][y + h];
        arr[x + w][y] = !arr[x + w][y];
        arr[x + w][y + h] = !arr[x + w][y + h];
    }
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            arr[i][j] = arr[i][j] ^ arr[i - 1][j] ^ arr[i][j - 1] ^ arr[i - 1][j - 1];
            ans += arr[i][j];
        }
    }
    printf("%d\n", ans);
    
    return 0;
}
