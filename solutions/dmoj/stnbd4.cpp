/*
 Solution to Ellis Fahrengart by Ava Pun
 Key concepts: binary indexed tree, Mo's
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair< pii, pair<int, ll> > piii;

int N, Q, BLOCK_SIZE;
int tree[100001];
pii arr[100001];
piii queries[100001];

bool comp1(pii a, pii b) {
    return a.second < b.second;
}
bool comp2(piii a, piii b) {
    return a.second.first < b.second.first;
}
bool moComp(piii a, piii b) {
    int block1 = a.first.first / BLOCK_SIZE;
    int block2 = b.first.first / BLOCK_SIZE;
    if (block1 != block2) {
        return block1 < block2;
    } else {
        return a.first.second < b.first.second;
    }
}

void update(int pos, int x) {
    for (int i = pos; i <= N; i += i & -i) {
        tree[i] += x;
    }
}

int query(int pos) {
    int sum = 0;
    for (int i = pos; i > 0; i -= i & -i) {
        sum += tree[i];
    }
    return sum;
}

int main() {
    
    scanf("%d", &N);
    BLOCK_SIZE = sqrt(N);
    int a, b;
    for (int i = 0; i < N; i++) {
        scanf("%d", &a);
        arr[i] = {a, i};
    }
    
    sort(arr, arr + N);
    int tmp = arr[0].first;
    int rank = 1;
    arr[0].first = rank;
    for (int i = 1; i < N; i++) {
        if (arr[i].first != tmp) {
            rank++;
        }
        tmp = arr[i].first;
        arr[i].first = rank;
    }
    sort(arr, arr + N, comp1);
    
    scanf("%d", &Q);
    for (int i = 0; i < Q; i++) {
        scanf("%d%d", &a, &b);
        queries[i] = {{a - 1, b - 1}, {i, 0}};
    }
    sort(queries, queries + Q, moComp);
    
    int idxl = 0, idxr = 0;
    ll sum = 0;
    for (int i = 0; i < Q; i++) {
        int l = queries[i].first.first;
        int r = queries[i].first.second;
        while (idxl < l) {
            update(arr[idxl].first, -1);
            sum -= query(arr[idxl].first - 1);
            idxl++;
        }
        while (idxl > l) {
            idxl--;
            update(arr[idxl].first, 1);
            sum += query(arr[idxl].first - 1);
        }
        while (idxr <= r) {
            sum += query(N) - query(arr[idxr].first);
            update(arr[idxr].first, 1);
            idxr++;
        }
        while (idxr > r + 1) {
            idxr--;
            sum -= query(N) - query(arr[idxr].first);
            update(arr[idxr].first, -1);
        }
        queries[i].second.second = sum;
    }
    sort(queries, queries + Q, comp2);
    
    for (int i = 0; i < Q; i++) {
        printf("%lld\n", queries[i].second.second);
    }
    
    return 0;
    
}
