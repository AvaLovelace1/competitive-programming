/*
 * Solution to Jury Marks by Ava Pun
 * Key concepts: brute force
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

int K, N;
int marks[2002];
int arr[2002];

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> K >> N;
    for (int i = 1; i <= K; ++i) {
        cin >> marks[i];
    }
    for (int i = 1; i <= N; ++i) {
        cin >> arr[i];
    }

    set<int> ans;
    int tot = 0;
    for (int i = 1; i <= K; ++i) {
        tot += marks[i];
        int beg = arr[1] - tot;
        int pts = beg;
        multiset<int> ss;
        for (int j = 1; j <= K; ++j) {
            pts += marks[j];
            ss.insert(pts);
        }
        bool good = true;
        for (int j = 1; j <= N; ++j) {
            auto it = ss.find(arr[j]);
            if (it == ss.end()) {
                good = false;
                break;
            } else {
                ss.erase(it);
            }
        }
        if (good) {
            ans.insert(beg);
        }
    }
    cout << ans.size() << '\n';

}
