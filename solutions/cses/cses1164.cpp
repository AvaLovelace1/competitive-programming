/*
 * Solution to Room Allocation by Ava Pun
 * Key concepts: greedy algorithms, sets
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
const int MAX = 2e5 + 2;

int N;
piii arr[2 * MAX];
int room[MAX];

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; ++i) {
        int a, b;
        cin >> a >> b;
        arr[i] = {{a, 0}, i};
        arr[i + N] = {{b, 1}, i};
    }
    sort(arr + 1, arr + 2 * N + 1);

    int K = 0;
    set<int> rooms;
    for (int i = 1; i <= 2 * N; ++i) {
        int p = arr[i].s;
        if (arr[i].f.s == 0) { // arrival
            if (rooms.empty()) {
                ++K;
                room[p] = K;
            } else {
                int rm = *rooms.begin();
                room[p] = rm;
                rooms.erase(rm);
            }
        } else {
            rooms.insert(room[p]);
        }
    }
    cout << K << '\n';
    for (int i = 1; i <= N; ++i) {
        cout << room[i] << (i == N ? '\n' : ' ');
    }

}
