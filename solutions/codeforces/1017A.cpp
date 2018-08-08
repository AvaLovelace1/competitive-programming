/*
 Solution to The Rank by Ava Pun
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
typedef pair<pii, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 1e3 + 5;

int N;
int arr[MAX], sorted[MAX];

inline bool comp(int a, int b) {
    if (arr[a] == arr[b]) {
        return a < b;
    }
    return arr[a] > arr[b];
}

int main() {
    
    scanf("%d", &N);
    int n;
    for (int i = 1; i <= N; i++) {
        sorted[i] = i;
        for (int j = 1; j <= 4; j++) {
            scanf("%d", &n);
            arr[i] += n;
        }
    }
    sort(sorted + 1, sorted + N + 1, comp);
    for (int i = 1; i <= N; i++) {
        if (sorted[i] == 1) {
            printf("%d\n", i);
            return 0;
        }
    }
    
    return 0;
}
