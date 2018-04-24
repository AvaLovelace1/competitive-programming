/*
 Solution to CCC '03 S4 - Substrings by Ava Pun
 Key concepts: suffix array
 */

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int T, N;
string s;
piii suff[5001];
int lcp[5001];
int idx[5001];

bool comp(piii a, piii b) {
    return a.second < b.second;
}

int main() {
    
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    
    while (T--) {
        
        cin >> s;
        N = (int) s.length();
        
        for (int i = 0; i < N; i++) {
            suff[i] = {i, {s[i], i + 1 < N ? s[i + 1] : -1}};
        }
        
        sort(suff, suff + N, comp);
        
        for (int k = 4; k < 2 * N; k *= 2) {
            
            int rank = 0, prev = suff[0].second.first;
            suff[0].second.first = rank;
            idx[suff[0].first] = 0;
            
            for (int i = 1; i < N; i++) {
                if (suff[i].second.first == prev && suff[i].second.second == suff[i - 1].second.second) {
                    prev = suff[i].second.first;
                    suff[i].second.first = rank;
                } else {
                    prev = suff[i].second.first;
                    rank++;
                    suff[i].second.first = rank;
                }
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
                while (i + len < N && j + len < N && s[i + len] == s[j + len]) {
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
        
        int ans = N - suff[0].first;
        for (int i = 0; i < N - 1; i++) {
            ans += N - suff[i + 1].first - lcp[i];
        }
        ans++;
        
        printf("%d\n", ans);
    }
    
    return 0;
}
