/*
 Solution to CCO '10 P3 - Wowow by Ava Pun
 Key concepts: binary indexed tree, binary search
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<char, pii> piii;
typedef vector<int> vi;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

int N, h;
piii quers[MAX];
int toRnk[MAX], fToIdx[MAX], idxToF[MAX];
unordered_map<int, int> toIdx;
int cnt = 1, currCnt = 0;
int bit[(1 << (sizeof(int) * 8 - __builtin_clz(MAX))) + 5];

void update(int pos, int x) {
    for (int i = pos; i <= h; i += i & -i) {
        bit[i] += x;
    }
}

int query(int x, int pos, int jump) {
    if (jump == 0) {
        return pos + 1;
    }
    if (bit[pos + jump] >= x) {
        return query(x, pos, jump >> 1);
    } else {
        return query(x - bit[pos + jump], pos + jump, jump >> 1);
    }
}

int main() {

    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf(" %c", &quers[i].f);
        if (quers[i].f == 'Q') {
            scanf("%d", &quers[i].s.f);
        } else {
            scanf("%d%d", &quers[i].s.f, &quers[i].s.s);
            toRnk[cnt++] = quers[i].s.s;
        }
    }
    
    h = 1 << (sizeof(int) * 8 - __builtin_clz(cnt));
    sort(toRnk + 1, toRnk + cnt);
    for (int i = 1; i < cnt; i++) {
        toIdx[toRnk[i]] = i;
    }
    
    for (int i = 1; i <= N; i++) {
        if (quers[i].f == 'Q') {
            int ans = query(currCnt - quers[i].s.f + 1, 0, h);
            printf("%d\n", idxToF[ans]);
        } else {
            int x = quers[i].s.f, r = quers[i].s.s;
            int idx = toIdx[r];
            if (quers[i].f == 'N') {
                currCnt++;
                fToIdx[x] = idx;
                idxToF[idx] = x;
                update(idx, 1);
            } else {
                update(fToIdx[x], -1);
                fToIdx[x] = idx;
                idxToF[idx] = x;
                update(idx, 1);
            }
        }
    }

    return 0;
    
}
