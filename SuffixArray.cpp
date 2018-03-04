/*
 ~ Suffix Array & LCP Array ~
 
 A sorted array of all the suffixes of a string.
 Can do pretty much anything a suffix tree can do, but is much less cancerous.
 Build complexity can be reduced to NlogN using radix sort or N using a suffix tree.
 Longest Common Prefix Array can be constructed from suffix array in linear time.
 
 Time complexity:
 Build suffix array - O(Nlog^2N)
 Build LCP array - O(N)
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

int N;
string S;
piii suff[MAX];
int idx[MAX], lcp[MAX];

bool comp(piii a, piii b) {
    return a.second < b.second;
}

void buildSuff() {
    
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
}

void buildLCP() {
    
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
    
}

int main() {
    
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> S;
    N = (int) S.length();
    
    buildSuff();
    buildLCP();
    
    for (int i = 0; i < N; i++) {
        cout << S.substr(suff[i].first, string::npos) << ", LCP: " << lcp[i] << "\n";
    }
    
    return 0;
    
}

