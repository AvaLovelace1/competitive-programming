/*
 Solution to COCI '14 Contest 3 #4 Coci by Ava Pun
 Key concepts: 2D prefix sum array
 */
 
#include <bits/stdc++.h>

using namespace std;

int N;
pair<int, int> scores[500001];
int pref[655][655] = {};

int query(int x1, int y1, int x2, int y2) {
    return pref[x2][y2] - pref[x1 - 1][y2] - pref[x2][y1 - 1] + pref[x1 - 1][y1 - 1];
}

int main() {
    
    scanf("%d", &N);
    
    int a, b;
    for (int i = 0; i < N; i++) {
        scanf("%d%d", &a, &b);
        a++;
        b++;
        scores[i] = {a, b};
        pref[a][b]++;
    }
    
    for (int i = 1; i <= 651; i++) {
        for (int j = 1; j <= 651; j++) {
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + pref[i][j];
        }
    }
    
    int best, worst;
    for (int i = 0; i < N; i++) {
        worst = N - query(1, 1, scores[i].first - 1, scores[i].second - 1);
        best = query(scores[i].first + 1, scores[i].second + 1, 651, 651) + 1;
        if (scores[i].first == 651) {
            worst -= query(1, scores[i].second, 1, scores[i].second);
        }
        if (scores[i].second == 651) {
            worst -= query(scores[i].first, 1, scores[i].first, 1);
        }
        printf("%d %d\n", best, worst);
    }
    
    return 0;
    
}
