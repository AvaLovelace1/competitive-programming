/*
 Solution to TLE '17 Contest 7 P2 - Airport Hopping by Ava Pun
 Key concepts: greedy algorithms, implementation
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
const int MAX = 1e5 + 5;

int N, M;
vii arr[MAX];
int d = 0, h = 0, m = 0;

int getHr() {
    return m > 0 ? (h + 1) % 24 : h;
}

void addH(int n) {
    h += n;
    if (h >= 24) {
        d += h / 24;
        h %= 24;
    }
}

void addM(int n) {
    m += n;
    if (m >= 60) {
        addH(m / 60);
        m %= 60;
    }
}

int main() {

    scanf("%d%d", &N, &M);
    int a, b, c;
    for (int i = 1; i <= M; i++) {
        scanf("%d%d%d", &a, &b, &c);
        arr[a].pb({b, c});
    }
    
    for (int i = 1; i < N; i++) {
        addM(20);
        if (m > 0) {
            addH(1);
            m = 0;
        }
        int minN = INF;
        for (pii p : arr[i]) {
            minN = min(minN, (p.f - getHr() + 24) % 24 + p.s);
        }
        //printf("%d\n", minN);
        addH(minN);
        addM(20);
    }
    
    if (m > 0) {
        addH(1);
        m = 0;
    }
    printf("Day %d Hour %d\n", d, h);
    
    return 0;
}
