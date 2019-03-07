/*
 Solution to USACO '19 February P1 - Cow Dating by Ava Pun
 Key concepts: two pointers, mathematics
 */

#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6 + 5;

int N;
double arr[MAX];

int main() {
    
    freopen("cowdate.in", "r", stdin);
    freopen("cowdate.out", "w", stdout);

    scanf("%d", &N);
    int n;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &n);
        arr[i] = n / 1000000.0;
    }
    
    double ans = 0, pref = 1, pre = 0, curr = 0;
    int j = 0;
    for (int i = 1; i <= N; i++) {
        while (j < N) {
            curr = pre * (1 - arr[j + 1]) + arr[j + 1] * pref;
            if (curr < pre) {
                break;
            }
            j++;
            pre = curr;
            pref *= 1 - arr[j];
        }
        ans = max(ans, pre);
        pref /= 1 - arr[i];
        pre = (pre - arr[i] * pref) / (1 - arr[i]);
    }
    printf("%d\n", (int) (ans * 1000000));
    
    return 0;
}
