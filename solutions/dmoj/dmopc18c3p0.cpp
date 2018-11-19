/*
 Solution to DMOPC '18 Contest 3 P0 - Bob and ICS Class by Ava Pun
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
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

int arr[2][3];

int main() {
    
    bool ans = 1;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &arr[i][j]);
            assert(arr[i][j] >= 0 && arr[i][j] <= 1e9);
            arr[i][j] = sqrt(arr[i][j]);
        }
    }
    for (int j = 0; j < 3; j++) {
        ans &= arr[0][j] == arr[1][j];
    }
    printf(ans ? "Dull\n" : "Colourful\n");
    
    return 0;
}
