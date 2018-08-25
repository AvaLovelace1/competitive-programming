/*
 Solution to IOI '15 P5 - Sorting by Ava Pun
 Key concepts: binary search
 */

#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e5 + 5;

int N, M;
int S[MAX], X[3 * MAX], Y[3 * MAX], P[MAX], Q[MAX];
int targ[MAX], idxT[MAX], seq[MAX], idxS[MAX];

inline void Swap(int a, int b, int seq[], int idx[]) {
    swap(seq[idx[a]], seq[idx[b]]);
    swap(idx[a], idx[b]);
}

inline int check(int k, int p[], int q[]) {
    
    fill(p, p + M, 0), fill(q, q + M, 0);
    for (int i = 0; i < N; i++) {
        targ[i] = idxT[i] = i;
    }
    for (int i = 0; i < k; i++) {
        Swap(X[i], Y[i], targ, idxT);
    }
    
    for (int i = 0; i < N; i++) {
        seq[i] = S[i];
        idxS[seq[i]] = i;
    }
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        int u = i;
        while (idxS[u] != idxT[u]) {
            int v = seq[idxT[u]];
            P[cnt] = u, Q[cnt] = v;
            cnt++;
            Swap(u, v, seq, idxS);
            u = v;
        }
    }
    
    if (cnt > k) {
        return -1;
    }
    for (int i = 0; i < N; i++) {
        seq[i] = S[i];
        idxS[seq[i]] = i;
    }
    for (int i = 0; i < k; i++) {
        Swap(seq[X[i]], seq[Y[i]], seq, idxS);
        if (i < cnt) {
            p[i] = idxS[P[i]], q[i] = idxS[Q[i]];
            Swap(P[i], Q[i], seq, idxS);
        }
    }
    return k;
}

int findSwapPairs(int n, int s[], int m, int x[], int y[], int p[], int q[]) {
    
    N = n, M = m;
    for (int i = 0; i < N; i++) {
        S[i] = s[i];
    }
    for (int i = 0; i < M; i++) {
        X[i] = x[i];
        Y[i] = y[i];
    }
    
    int lo = 0, hi = M, mid;
    while (lo < hi) {
        mid = (lo + hi) / 2;
        if (check(mid, p, q) != -1) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return check(lo, p, q);
}

int main() {
    int N, M;
    scanf("%d", &N);
    int *S = (int*)malloc(sizeof(int) * (unsigned int)N);
    for (int i = 0; i < N; ++i)
        scanf("%d", &S[i]);
    scanf("%d", &M);
    int *X = (int*)malloc(sizeof(int) * (unsigned int)M), *Y = (int*)malloc(sizeof(int) * (unsigned int)M);
    for (int i = 0; i < M; ++i) {
        scanf("%d%d", &X[i], &Y[i]);
    }
    int *P = (int*)malloc(sizeof(int) * (unsigned int)M), *Q = (int*)malloc(sizeof(int) * (unsigned int)M);
    int ans = findSwapPairs(N, S, M, X, Y, P, Q);
    printf("%d\n", ans);
    for (int i = 0; i < ans; ++i)
        printf("%d %d\n", P[i], Q[i]);
    return 0;
}
