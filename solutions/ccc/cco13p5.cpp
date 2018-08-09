/*
 Solution to CCO '13 P5 - Transforming Comets by Ava Pun
 Key concepts: geometry, KMP
 */

#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const int MAX = 5e5 + 5;

int t, N;
pii arr1[MAX], arr2[MAX];
double angs1[MAX], angs2[MAX], str[3 * MAX];
int lps[3 * MAX];

inline double mag(pii p) {
    return sqrt((ll) p.X * p.X + (ll) p.Y * p.Y);
}

inline double angle(pii a, pii b, pii c) {
    a.X -= b.X, a.Y -= b.Y;
    c.X -= b.X, c.Y -= b.Y;
    ll dot = (ll) a.X * c.Y - (ll) a.Y * c.X, cross = (ll) a.X * c.X + (ll) a.Y * c.Y;
    return atan2(cross, dot) * (mag(a) / mag(c));
}

inline void getAngles(pii arr[], double v[]) {
    for (int i = 0; i < N; i++) {
        pii a = arr[i], b = arr[(i + 1) % N], c = arr[(i + 2) % N];
        v[i] = angle(a, b, c);
    }
}

int kmp() {
    
    lps[0] = 0;
    for (int i = 1; i < 3 * N + 1; i++) {
        int j = lps[i - 1];
        while (j > 0 && abs(str[i] - str[j]) > 1e-9) {
            j = lps[j - 1];
        }
        if (abs(str[i] - str[j]) <= 1e-9) {
            j++;
        }
        lps[i] = j;
        if (lps[i] == N) {
            return i - 2 * N + 1;
        }
    }
    
    return 0;
}

int main() {
    
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            scanf("%d%d", &arr1[i].X, &arr1[i].Y);
        }
        for (int i = 0; i < N; i++) {
            scanf("%d%d", &arr2[i].X, &arr2[i].Y);
        }
        getAngles(arr1, angs1), getAngles(arr2, angs2);
        for (int i = 0; i < N; i++) {
            str[i] = angs1[i];
        }
        str[N] = INFL;
        for (int i = 0; i < N; i++) {
            str[i + N + 1] = angs2[i];
        }
        for (int i = 0; i < N; i++) {
            str[i + 2 * N + 1] = angs2[i];
        }
        printf("%d\n", kmp());
    }
    
    return 0;
}
