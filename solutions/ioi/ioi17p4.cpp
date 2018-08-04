/*
 Solution to IOI '17 P4 - The Big Prize by Ava Pun
 Key concepts: binary search
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
const int MAX = 2e5 + 5;

vi quers[MAX];
map<int, set<int>> pos;

int find_best(int n) {
    
    stack<pii> st;
    st.push({0, n - 1});
    
    while (!st.empty()) {
        
        pii x = st.top();
        st.pop();
        int lo = x.f, hi = x.s, mid = (lo + hi) / 2;
        
        if (lo > hi) {
            continue;
        } else {
            bool good = 1;
            for (auto &p : pos) {
                auto loIt = p.s.lower_bound(lo), hiIt = p.s.upper_bound(hi);
                if (hiIt != p.s.end() && loIt != p.s.begin()) {
                    loIt--;
                    int lo0 = *loIt, hi0 = *hiIt;
                    if (quers[hi0][0] - quers[lo0][0] == 0) {
                        good = 0;
                        break;
                    }
                }
            }
            if (!good) {
                continue;
            }
        }
        
        quers[mid] = ask(mid);
        int k = quers[mid][0] + quers[mid][1];
        pos[k].insert(mid);
        if (k == 0) {
            return mid;
        } else {
            st.push({lo, mid - 1}), st.push({mid + 1, hi});
        }        
    }
    
    return -1;
}
