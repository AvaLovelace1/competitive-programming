/*
 Solution to Segment Tree Test by Ava Pun
 Key concepts: segment tree
 */

#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 5;

int N, M;
int arr[MAX];
int minTree[2 * MAX];
pair<int, int> gcfTree[2 * MAX];

void update(int idx, int x) {
    arr[idx] = x;
    idx += N - 1;
    minTree[idx] = x;
    gcfTree[idx].first = x;
    for (int i = idx >> 1; i > 1; i >>= 1) {
        minTree[i] = min(minTree[i << 1], minTree[i << 1 | 1]);
        gcfTree[i].first = __gcd(gcfTree[i << 1].first, gcfTree[i << 1 | 1].first);
        int count = 0;
        if (gcfTree[i].first == gcfTree[i << 1].first) {
            count += gcfTree[i << 1].second;
        }
        if (gcfTree[i].first == gcfTree[i << 1 | 1].first) {
            count += gcfTree[i << 1 | 1].second;
        }
        gcfTree[i].second = count;
    }
}

void build() {
    for (int i = 1; i <= N; i++) {
        minTree[i + N - 1] = arr[i];
        gcfTree[i + N - 1].first = arr[i];
        gcfTree[i + N - 1].second = 1;
    }
    for (int i = N - 1; i > 0; i--) {
        minTree[i] = min(minTree[i << 1], minTree[i << 1 | 1]);
        gcfTree[i].first = __gcd(gcfTree[i << 1].first, gcfTree[i << 1 | 1].first);
        int count = 0;
        if (gcfTree[i].first == gcfTree[i << 1].first) {
            count += gcfTree[i << 1].second;
        }
        if (gcfTree[i].first == gcfTree[i << 1 | 1].first) {
            count += gcfTree[i << 1 | 1].second;
        }
        gcfTree[i].second = count;
    }
}

int minQuery(int l, int r) {
    int minN = INT_MAX;
    l += N - 1;
    r += N - 1;
    while (l <= r) {
        if (l & 1) {
            minN = min(minN, minTree[l]);
            l++;
        }
        if (!(r & 1)) {
            minN = min(minN, minTree[r]);
            r--;
        }
        l >>= 1;
        r >>= 1;
    }
    return minN;
}

int gcfQuery(int l, int r) {
    int gcf = arr[l];
    l += N - 1;
    r += N - 1;
    while (l <= r) {
        if (l & 1) {
            gcf = __gcd(gcf, gcfTree[l].first);
            l++;
        }
        if (!(r & 1)) {
            gcf = __gcd(gcf, gcfTree[r].first);
            r--;
        }
        l >>= 1;
        r >>= 1;
    }
    return gcf;
}

int countQuery(int l, int r) {
    int gcf = gcfQuery(l, r);
    int count = 0;
    l += N - 1;
    r += N - 1;
    while (l <= r) {
        if (l & 1) {
            if (gcfTree[l].first == gcf) {
                count += gcfTree[l].second;
            }
            l++;
        }
        if (!(r & 1)) {
            if (gcfTree[r].first == gcf) {
                count += gcfTree[r].second;
            }
            r--;
        }
        l >>= 1;
        r >>= 1;
    }
    return count;
}

int main() {
    
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
    }
    
    build();
    
    char c;
    int a, b;
    for (int i = 1; i <= M; i++) {
        scanf(" %c%d%d", &c, &a, &b);
        if (c == 'C') {
            update(a, b);
        } else if (c == 'M') {
            printf("%d\n", minQuery(a, b));
        } else if (c == 'G') {
            printf("%d\n", gcfQuery(a, b));
        } else {
            printf("%d\n", countQuery(a, b));
        }
    }
    
    return 0;
    
}
