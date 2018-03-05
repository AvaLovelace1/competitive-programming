/*
 Solution to DMOPC '16 Contest 4 P3 - Carnival Phantasm by Ava Pun
 Key concepts: ordered set
 */
 
#include <bits/stdc++.h>

using namespace std;

int N, S, Q;

pair< int, set<int> > stalls[100001];
struct comp {
    bool operator() (int a, int b) {
        if (stalls[a].first == stalls[b].first) {
            return a < b;
        } else {
            return stalls[a].first < stalls[b].first;
        }
    }
};
set<int, comp> apples[101];

int main() {
    
    scanf("%d%d", &N, &S);
    int a, b;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &a);
        stalls[i].first = a;
    }
    while (S--) {
        scanf("%d%d", &a, &b);
        stalls[a].second.insert(b);
        apples[b].insert(a);
    }
    
    scanf("%d", &Q);
    char c;
    while (Q--) {
        scanf(" %c", &c);
        if (c == 'A') {
            scanf("%d%d", &a, &b);
            stalls[a].second.insert(b);
            apples[b].insert(a);
        } else if (c == 'S') {
            scanf("%d%d", &a, &b);
            stalls[a].second.erase(b);
            apples[b].erase(a);
        } else if (c == 'E') {
            scanf("%d%d", &a, &b);
            for (int apple : stalls[a].second) {
                apples[apple].erase(a);
            }
            stalls[a].second.clear();
            stalls[a].first = b;
        } else {
            scanf("%d", &a);
            if (!apples[a].empty()) {
                printf("%d\n", *apples[a].begin());
            } else {
                printf("-1\n");
            }
        }
    }
    
    return 0;
}
