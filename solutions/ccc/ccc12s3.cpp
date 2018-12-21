/*
 Solution to CCC '12 S3 - Absolutely Acidic by Ava Pun
 Key concepts: implementation
 */
 
 #include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int N;
pii arr[1000];

int main() {
    
    scanf("%d", &N);
    int n;
    for (int i = 0; i < 1000; i++) {
        arr[i] = {0, i + 1};
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &n);
        arr[n - 1].first++;
    }
    
    sort(arr, arr + 1000);

    int diff;
    pii p = {arr[999].first, 0};
    auto itr = lower_bound(arr, arr + 1000, p);
    if (itr == arr + 999) {
        p = {arr[998].first, 0};
        auto itr1 = lower_bound(arr, arr + 1000, p);
        diff = abs(arr[999].second - (*itr1).second);
        diff = max(diff, abs(arr[999].second - arr[998].second));
    } else {
        diff = abs(arr[999].second - (*itr).second);
    }
    
    printf("%d", diff);
    
    return 0;
    
}
