/*
 * Solution to USACO '18 February G1 - Snow Boots by Ava Pun
 * Key concepts: sorting, set
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

using ll = long long int;
using pii = pair<int, int>;
using piii = pair<int, pii>;
using vi = vector<int>;
using vii = vector<pii>;
const int INF = 0x3F3F3F3F;
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const int MAX = 1e5 + 2;

int N, B;
pii arr[MAX];
struct boot {
    int idx, dep, step;
} boots[MAX];
int ans[MAX];

bool comp(boot a, boot b) {
    return a.dep < b.dep;
}

set<int> posns;
map<int, int> lens;
void insert(map<int, int> &mp, int x) {
    ++mp[x];
}
void erase(map<int, int> &mp, int x) {
    --mp[x];
    if (mp[x] <= 0) {
        mp.erase(x);
    }
}
void add(int pos) {
    if (posns.find(pos) != posns.end()) {
        return;
    }
    auto ub = posns.upper_bound(pos);
    auto lb = ub; --lb;
    erase(lens, *ub - *lb);
    insert(lens, *ub - pos);
    insert(lens, pos - *lb);
    posns.insert(pos);
}

bool check(int step) {
    int longest = (*(--lens.end())).f;
    return step >= longest;
}

int main() {

    freopen("snowboots.in", "r", stdin);
    freopen("snowboots.out", "w", stdout);

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> B;
    for (int i = 1; i <= N; ++i) {
        cin >> arr[i].f;
        arr[i].s = i;
    }
    sort(arr + 1, arr + N + 1);

    for (int i = 1; i <= B; ++i) {
        int dep, step;
        cin >> dep >> step;
        boots[i] = boot{i, dep, step};
    }
    sort(boots + 1, boots + B + 1, comp);

    posns.insert(1);
    posns.insert(N);
    insert(lens, N - 1);

    int ptr = 1;
    for (int i = 1; i <= B; ++i) {
        while (ptr <= N && arr[ptr].f <= boots[i].dep) {
            add(arr[ptr].s);
            ++ptr;
        }
        ans[boots[i].idx] = check(boots[i].step);
    }
    for (int i = 1; i <= B; ++i) {
        cout << ans[i] << '\n';
    }

}
