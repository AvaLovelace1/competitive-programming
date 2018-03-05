/*
 Solution to COCI '06 Contest 5 #6 Dvaput by Ava Pun
 Key concepts: suffix array
 */
 
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 200005;

int N;
string S;
piii suff[MAX];
int idx[MAX], lcp[MAX];

bool comp(piii a, piii b) {
    return a.second < b.second;
}

int main() {
    
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    cin >> S;
    
    for (int i = 0; i < N; i++) {
        suff[i] = {i, {S[i], i + 1 < N ? S[i + 1] : -1}};
    }
    
    sort(suff, suff + N, comp);
    
    for (int k = 4; k < 2 * N; k *= 2) {
        
        int rank = 0, prev = suff[0].second.first;
        suff[0].second.first = rank;
        idx[suff[0].first] = 0;
        
        for (int i = 1; i < N; i++) {
            if (!(suff[i].second.first == prev && suff[i].second.second == suff[i - 1].second.second)) {
                rank++;
            }
            prev = suff[i].second.first;
            suff[i].second.first = rank;
            idx[suff[i].first] = i;
        }
        
        for (int i = 0; i < N; i++) {
            int next = suff[i].first + k / 2;
            suff[i].second.second = next < N ? suff[idx[next]].second.first : -1;
        }
        
        sort(suff, suff + N, comp);
        
    }
    
    for (int i = 0; i < N; i++) {
        idx[suff[i].first] = i;
    }
    
    int len = 0;
    
    for (int i = 0; i < N; i++) {
        if (idx[i] != N - 1) {
            int j = suff[idx[i] + 1].first;
            while (i + len < N && j + len < N && S[i + len] == S[j + len]) {
                len++;
            }
        } else {
            len = 0;
        }
        lcp[idx[i]] = len;
        if (len > 0) {
            len--;
        }
    }
    
    int maxN = 0;
    for (int i = 0; i < N; i++) {
        maxN = max(maxN, lcp[i]);
    }
    
    cout << maxN;
    
    return 0;
}
