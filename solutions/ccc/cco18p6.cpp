/*
 Solution to CCO '18 P6 - Flop Sorting by Ava Pun
 Key concepts: divide and conquer, merge sort
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
const int MAX = 4100;

int N;
int arr1[MAX], arr2[MAX];
vii ans1, ans2;

inline void fSwap(int l, int r, int arr[], vii &ans) {
    if (l == r) {
        return;
    }
    swap(arr[l], arr[r]);
    ans.pb({l, r});
}

inline void rev(int l, int r, int arr[], vii &ans) {
    for (int i = 0; i < (r + 1 - l) / 2; i++) {
        fSwap(l + i, r - i, arr, ans);
    }
}

void fMerge(int l, int m, int r, int arr[], vii &ans) {
    if (l >= r || m > r || m <= l) {
        return;
    } else {
        int n = (r + 1 - l) / 2;
        int i = 0, j = 0;
        while (i + j < n) {
            if (m + j > r) {
                i++;
            } else if (l + i >= m) {
                j++;
            } else if (arr[l + i] < arr[m + j]) {
                i++;
            } else {
                j++;
            }
        }
        int m1 = l + i, m2 = m + j;
        rev(m1, m - 1, arr, ans), rev(m, m2 - 1, arr, ans);
        rev(m1, m2 - 1, arr, ans);
        m = l + n;
        fMerge(l, m1, m - 1, arr, ans), fMerge(m, m2, r, arr, ans);
    }
}

void fSort(int l, int r, int arr[], vii &ans) {
    if (l >= r) {
        return;
    } else {
        int m = (l + r) / 2;
        fSort(l, m, arr, ans), fSort(m + 1, r, arr, ans);
        fMerge(l, m + 1, r, arr, ans);
    }
}

int main() {
    
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr1[i]);
    }
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr2[i]);
    }
    
    fSort(1, N, arr1, ans1);
    fSort(1, N, arr2, ans2);
    
    reverse(ans2.begin(), ans2.end());
    printf("%d\n", (int) ans1.size() + (int) ans2.size());
    for (pii p : ans1) {
        printf("%d %d\n", p.f, p.s);
    }
    for (pii p : ans2) {
        printf("%d %d\n", p.f, p.s);
    }
    
    return 0;
}
