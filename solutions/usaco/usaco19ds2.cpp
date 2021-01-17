/*
 * Solution to USACO '19 December S2 - Meetings by Ava Pun
 * Key concepts: sorting
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

using ll = long long int;
using pii = pair<int, int>;
using piii = pair<pii, int>;
using vi = vector<int>;
using vii = vector<pii>;
const int INF = 0x3F3F3F3F;
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const int MAX = 1e5+2;

int N, L;
int NF = 0, NB = 0;
int fwd[MAX], bwd[MAX];
int totWeight = 0;
pii weights[MAX];

ll nMeetings(int t) {
    ll ans = 0;
    int l = 1, r = 0;
    for (int i = 1; i <= NF; ++i) {
        while (l <= NB && bwd[l] - fwd[i] < 0) {
            ++l;
        }
        while (r < NB && bwd[r + 1] - fwd[i] <= 2 * t) {
            ++r;
        }
        ans += r - l + 1;
    }
    return ans;
}

int main() {

    freopen("meetings.in", "r", stdin);
    freopen("meetings.out", "w", stdout);

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> L;

    for (int i = 1; i <= N; ++i) {
        int w, x, d;
        cin >> w >> x >> d;
        if (d == 1) {
            ++NF;
            fwd[NF] = x;
        } else {
            ++NB;
            bwd[NB] = x;
        }
        totWeight += w;
        weights[i] = {x, w};
    }
    sort(fwd + 1, fwd + NF + 1);
    sort(bwd + 1, bwd + NB + 1);
    sort(weights + 1, weights + N + 1);

    int idxF = NF, idxB = 1;
    int idxWL = 1, idxWR = N;
    int t = 0;
    int curTot = 0;
    for (int i = 1; i <= N; ++i) {
        int newT = min(L - fwd[idxF], bwd[idxB]);
        if (idxF >= 1 && L - fwd[idxF] == newT) {
            curTot += weights[idxWR].s;
            --idxF;
            --idxWR;
        }
        if (idxB <= NB && bwd[idxB] == newT) {
            curTot += weights[idxWL].s;
            ++idxB;
            ++idxWL;
        }
        t = newT;
        if (curTot * 2 >= totWeight) {
            break;
        }
    }
    cout << nMeetings(t) << '\n';

}
