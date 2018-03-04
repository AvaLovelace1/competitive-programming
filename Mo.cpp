/*
 ~ Mo's Algorithm ~
 
 Algorithm for processing offline queries.
 Reorders the queries to efficiently solve them.
 
 Time complexity: O(QsqrtN*F)
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

int N, Q;
int BLOCK_SIZE;
int arr[MAX];
piii queries[MAX];
int answers[MAX];

bool moComp(piii a, piii b) {
    int blockA = a.first.first / BLOCK_SIZE;
    int blockB = b.first.first / BLOCK_SIZE;
    if (blockA == blockB) {
        return a.first.second < b.first.second;        
    } else {
        return blockA < blockB;
    }
}

void mo() {
    
    sort(queries, queries + Q, moComp);
    int idxl = 0, idxr = 0, sum = 0;
    
    for (int i = 0; i < Q; i++) {
        
        int l = queries[i].first.first;
        int r = queries[i].first.second;
        
        while (idxl < l) {
            sum -= arr[idxl];
            idxl++;
        }
        while (idxl > l) {
            idxl--;
            sum += arr[idxl];
        }
        while (idxr < r + 1) {
            sum += arr[idxr];
            idxr++;
        }
        while (idxr > r + 1) {
            idxr--;
            sum -= arr[idxr];
        }
        answers[queries[i].second] = sum;
    }
    
}

int main() {
    
    scanf("%d", &N);
    BLOCK_SIZE = sqrt(N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &Q);
    for (int i = 0; i < Q; i++) {
        scanf("%d%d", &queries[i].first.first, &queries[i].first.second);
        queries[i].second = i;
    }
    
    mo();
    for (int i = 0; i < Q; i++) {
        printf("%d\n", answers[i]);
    }
    
    return 0;
    
}
