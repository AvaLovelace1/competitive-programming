/*
 Solution to The hat by Ava Pun
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
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

int N;

inline int scan(int i) {
    printf("? %d\n", i);
    fflush(stdout);
    int ans;
    scanf("%d", &ans);
    return ans;
}

inline int query(int i) {
    return scan(i) - scan(i + N / 2);
}

inline void answer(int i) {
    printf("! %d\n", i);
    fflush(stdout);
    exit(0);
}

int main() {

    scanf("%d", &N);
    
    int lo = 1, hi = 1 + N / 2, mid;
    int loQ = query(lo), hiQ = -loQ, midQ;
    if (loQ % 2 != 0) {
        answer(-1);
    } else if (loQ == 0) {
        answer(lo);
    }
    
    lo++, hi--;
    while (lo < hi) {
        mid = (lo + hi) / 2;
        midQ = query(mid);
        if (midQ == 0) {
            answer(mid);
        } else if ((ll) loQ * midQ < 0) {
            hi = mid - 1;
            hiQ = midQ;
        } else {
            lo = mid + 1;
            loQ = midQ;
        }
    }
    
    answer(lo);
    
    return 0;
}
