/*
 Solution to DMOPC '16 Contest 4 P4 - Molly and Manga Shopping by Ava Pun
 Key concepts: Mo's
 */
 
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

int N, Q, BLOCK;
int arr[MAX], freq[MAX];
piii queries[MAX];
int ans[MAX];
unordered_set<int> s;

bool moComp(piii a, piii b) {
    int blockA = a.first.first / BLOCK;
    int blockB = b.first.first / BLOCK;
    if (blockA == blockB) {
        return a.first.second < b.first.second;
    } else {
        return blockA < blockB;
    }
}

int main() {
    
    scanf("%d", &N);
    BLOCK = sqrt(N);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
    }
    
    scanf("%d", &Q);
    for (int i = 0; i < Q; i++) {
        scanf("%d%d", &queries[i].first.first, &queries[i].first.second);
        queries[i].second = i;
    }
    sort(queries, queries + Q, moComp);
    
    int idxl = 0, idxr = 0, sum = 0;
    for (int i = 0; i < Q; i++) {
        int l = queries[i].first.first;
        int r = queries[i].first.second;
        int n;
        while (idxl < l) {
            n = arr[idxl];
            freq[n]--;
            sum += ((freq[n] + 2) % 2 == 0 ? freq[n] == 0 ? 0 : 1 : -1);
            idxl++;
        }
        while (idxl > l) {
            idxl--;
            n = arr[idxl];
            freq[n]++;
            sum += ((freq[n] + 2) % 2 == 0 ? 1 : freq[n] == 1 ? 0 : -1);
        }
        while (idxr < r + 1) {
            n = arr[idxr];
            freq[n]++;
            sum += ((freq[n] + 2) % 2 == 0 ? 1 : freq[n] == 1 ? 0 : -1);
            idxr++;
        }
        while (idxr > r + 1) {
            idxr--;
            n = arr[idxr];
            freq[n]--;
            sum += ((freq[n] + 2) % 2 == 0 ? freq[n] == 0 ? 0 : 1 : -1);
        }
        ans[queries[i].second] = sum;
    }
    
    for (int i = 0; i < Q; i++) {
        printf("%d\n", ans[i]);
    }
    
    return 0;
}
