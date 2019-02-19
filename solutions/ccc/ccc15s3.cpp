/*
 Solution to CCC '15 S3 - Gates by Ava Pun
 Key concepts: greedy algorithms, set
 */

#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 5;

int G, P;
set<int> open;

int main() {
    
    scanf("%d%d", &G, &P);
    for (int i = 1; i <= G; i++) {
        open.insert(i);
    }
    
    int ans = 0;
    bool closed = 0;
    int g;
    for (int i = 1; i <= P; i++) {
        scanf("%d", &g);
        if (!closed) {
            auto x = open.upper_bound(g);
            if (x != open.begin()) {
                --x;
                open.erase(x);
                ans++;
            } else {
                closed = 1;
            }
        }
    }
    printf("%d\n", ans);
    
    return 0;
}
