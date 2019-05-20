/*
 Solution to ECOO '19 R2 P3 - Ribbon by Ava Pun
 Key concepts: ad hoc, amortized analysis
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
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1e9 + 7;
const int MAX = 1e7 + 5;

int N, M;
int arr[3 * MAX];
bool rev;
int C, S, len, l, r;

inline int getPos(int pos) {
    return rev ? C * 2 - (pos + S) + 1 : pos + S;
}

inline void lfold(int pos, bool flip) {
    for (int i = l; i < pos; i++) {
        arr[pos + (pos - i) - 1] += arr[i];
        arr[i] = 0;
    }
    len -= pos - l;
    l = pos;
    if (flip) {
        if (rev) {
            S = getPos(0);
        }
        rev = !rev;
        C = pos - 1;
        if (!rev) {
            S = C * 2 - S + 1;
        }
    }
}

inline void rfold(int pos, bool flip) {
    for (int i = r; i > pos; i--) {
        arr[pos - (i - pos) + 1] += arr[i];
        arr[i] = 0;
    }
    len -= r - pos;
    r = pos;
    if (flip) {
        if (rev) {
            S = getPos(0);
        }
        rev = !rev;
        C = pos;
        if (!rev) {
            S = C * 2 - S + 1;
        }
    }
}

int main() {
    
    for (int test = 1; test <= 10; test++) {
        scanf("%d%d", &N, &M);
        FILL(arr, 0);
        fill(arr + 1 + N, arr + N + 1 + N, 1);
        rev = 0, C = 0, S = N, len = N;
        l = getPos(1), r = getPos(N);
        int pos;
        char c;
        while (M--) {
            scanf("%d %c", &pos, &c);
            pos = getPos(pos);
            if (len > 1) {
                if ((c == 'L' && !rev) || (c == 'R' && rev)) {
                    if (pos - l <= len / 2) {
                        lfold(pos, 0);
                    } else {
                        rfold(pos - 1, 1);
                    }
                } else {
                    if (r - pos <= len / 2) {
                        rfold(pos, 0);
                    } else {
                        lfold(pos + 1, 1);
                    }
                }
            }
        }
        printf("%d %d\n", len, *max_element(arr + l, arr + r + 1));
    }
    
    return 0;
}
