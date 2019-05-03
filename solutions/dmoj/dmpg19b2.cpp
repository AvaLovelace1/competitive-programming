/*
 Solution to DMPG '19 B2 - Rectangular Molecules by Ava Pun
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

int arr[4];

int main() {
    
    for (int i = 0; i < 4; i++) {
        scanf("%d", &arr[i]);
    }
    int maxPos = (int) (max_element(arr, arr + 4) - arr);
    arr[maxPos] = -1;
    int maxPos2 = (int) (max_element(arr, arr + 4) - arr);
    if (maxPos > maxPos2) {
        swap(maxPos, maxPos2);
    }
    printf(((maxPos == 0 && maxPos2 == 2) || (maxPos == 1 && maxPos2 == 3)) ? "trans\n" : "cis\n");
    
    return 0;
}
