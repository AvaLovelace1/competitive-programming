/*
 Solution to CCO '02 P4 - Duathlon by Ava Pun
 Key concepts: ternary search
 */

#include <bits/stdc++.h>

using namespace std;

int T, N;
double run[21], cycle[21];
double R, C;

double findTime(double dist, double r, double c) {
    return dist / r + (T - dist) / c;
}

double findMargin(double dist) {
    double cheater = findTime(dist, R, C);
    double minTime = INT64_MAX;
    for (int i = 0; i < N - 1; i++) {
        minTime = min(minTime, findTime(dist, run[i], cycle[i]));
    }
    return minTime - cheater;
}

int main() {
    
    scanf("%d%d", &T, &N);
    for (int i = 0; i < N - 1; i++) {
        scanf("%lf%lf", &run[i], &cycle[i]);
        run[i] /= 3600;
        cycle[i] /= 3600;
    }
    scanf("%lf%lf", &R, &C);
    R /= 3600;
    C /= 3600;
    
    double start = 0, end = T, mid1, mid2;
    for (int i = 0; i < 100; i++) {
        mid1 = (start * 2 + end) / 3;
        mid2 = (start + end * 2) / 3;
        if (findMargin(mid1) - findMargin(mid2) > 1e-9) {
            end = mid2;
        } else {
            start = mid1;
        }
    }
    
    start = round(start * 100) / 100;
    double margin = findMargin(start);
    if (margin < -1e-9) {
        printf("The cheater cannot win.");
    } else {
        printf("The cheater can win by %d seconds with r = %.2lfkm and k = %.2lfkm.", (int) round(margin), start, T - start);
    }
    
    return 0;
}
