/*
 Solution to IOI '98 P6 - Polygon by Ava Pun
 Key concepts: interval dynamic programming
 */
 
#include <bits/stdc++.h>

using namespace std;

const int MAX = 32767, MIN = -32767 - 1;
int N;
char c;
short int arr[51];
bool edges[51];
short int dpMax[51][51], dpMin[51][51];
bool dpMaxDone[51][51], dpMinDone[51][51];
short int solveMax(int n, int l, int r);

short int solveMin(int n, int l, int r) {
    if (!dpMinDone[l][r]) {
        int l0 = (l + n) % N;
        if (l == r) {
            dpMin[l][r] = arr[l0];
        } else {
            dpMin[l][r] = MAX;
            for (int i = l; i < r; i++) {
                short int maxL = solveMax(n, l, i), maxR = solveMax(n, i + 1, r),
                minL = solveMin(n, l, i), minR = solveMin(n, i + 1, r);
                if (edges[(i + n + 1) % N]) {
                    dpMin[l][r] = min(dpMin[l][r], (short int) (minL + minR));
                } else {
                    dpMin[l][r] = min(dpMin[l][r], (short int) min(min(minL * maxR, maxL * minR), min(minL * minR, maxL * maxR)));
                }
            }
        }
        //printf("Min %d %d %d\n", l, r, dpMin[l][r]);
        dpMinDone[l][r] = true;
    }
    return dpMin[l][r];
}

short int solveMax(int n, int l, int r) {
    if (!dpMaxDone[l][r]) {
        int l0 = (l + n) % N;
        if (l == r) {
            dpMax[l][r] = arr[l0];
        } else {
            dpMax[l][r] = MIN;
            for (int i = l; i < r; i++) {
                short int maxL = solveMax(n, l, i), maxR = solveMax(n, i + 1, r),
                minL = solveMin(n, l, i), minR = solveMin(n, i + 1, r);
                if (edges[(i + n + 1) % N]) {
                    dpMax[l][r] = max(dpMax[l][r], (short int) (maxL + maxR));
                } else {
                    dpMax[l][r] = max(dpMax[l][r], (short int) max(maxL * maxR, minL * minR));
                }
            }
        }
        //printf("Max %d %d %d\n", l, r, dpMax[l][r]);
        dpMaxDone[l][r] = true;
    }
    return dpMax[l][r];
}

int main() {
    
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf(" %c", &c);
        if (c == 't') {
            edges[i] = 1;
        } else {
            edges[i] = 0;
        }
        scanf("%hd", &arr[i]);
    }
    
    vector<int> ans;
    int maxN = MIN;
    for (int i = 0; i < N; i++) {
        memset(dpMaxDone, 0, sizeof(dpMaxDone));
        memset(dpMinDone, 0, sizeof(dpMinDone));
        int n = solveMax(i, 0, N - 1);
        if (n > maxN) {
            maxN = n;
            ans.clear();
            ans.push_back(i + 1);
        } else if (n == maxN) {
            ans.push_back(i + 1);
        }
    }
    
    printf("%d\n", maxN);
    for (int i : ans) {
        printf("%d ", i);
    }
    
    return 0;
}
