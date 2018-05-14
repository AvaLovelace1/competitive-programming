/*
 Solution to WC17 Finals - An Interspecific Army by Ava Pun
 Key concepts: greedy algorithms
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back

typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MAX = 1e5 + 5;

int N;
int arr1[MAX], arr2[MAX];

int main() {
    
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr1[i]);
    }
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr2[i]);
    }
    sort(arr1 + 1, arr1 + N + 1);
    sort(arr2 + 1, arr2 + N + 1);
    
    int ans = -1;
    for (int i = 1; i <= N; i++) {
        ans = max(ans, abs(arr1[i] - arr2[i]));
    }
    printf("%d\n", ans);

    return 0;
}
