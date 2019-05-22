/*
 Solution to CCO '14 P5 - Early Exam Evacuation by Ava Pun
 Key concepts: binary indexed tree
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second

typedef long long int ll;
typedef pair<int, int> pii;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MAX = 1e5 + 5;

int N, M, A, B;
pii arr[6 * MAX];
int bit[MAX];
int rows[MAX][7];

inline void upd(int pos, int x, int bit[], int N) {
    for (int i = pos; i <= N; i += i & -i) {
        bit[i] += x;
    }
}

inline int quer(int pos, int bit[]) {
    int ans = 0;
    for (int i = pos; i > 0; i -= i & -i) {
        ans += bit[i];
    }
    return ans;
}

inline int quer(int l, int r, int bit[]) {
    return quer(r, bit) - quer(l - 1, bit);
}

inline bool comp(pii a, pii b) {
    return a.f - a.s < b.f - b.s;
}

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> A >> B;
    for (int i = 1; i <= N; i++) {
        upd(i, 2, bit, N);
        for (int j = 1; j <= 6; j++) {
            upd(j, 1, rows[i], 6);
        }
    }

    string str;
    int r;
    char c;
    for (int i = 1; i <= M; i++) {
        cin >> str;
        r = stoi(str.substr(0, str.length() - 1));
        c = str[str.length() - 1];
        if (c == 'C' || c == 'D') {
            upd(r, -1, bit, N);
        }
        upd(c - 'A' + 1, -1, rows[r], 6);
        arr[i].f = arr[i].s = (c <= 'C' ? quer(c - 'A' + 2, 4, rows[r]) : quer(3, c - 'A', rows[r]));
        arr[i].f += quer(1, r - 1, bit);
        arr[i].s += quer(r + 1, N, bit);
    }
    sort(arr + 1, arr + M + 1, comp);

    ll tot = 0;
    ll ans = INFL;
    for (int i = 1; i <= M; i++) {
        tot += arr[i].s;
    }
    for (int i = 0; i <= M; i++) {
        tot += arr[i].f - arr[i].s;
        ll totB = ((ll) i * (i - 1) + (ll) (M - i) * (M - i - 1)) / 2;
        ans = min(ans, tot * A + totB * B);
    }
    cout << ans << '\n';

    return 0;
}
