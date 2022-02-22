/*
 * Solution to Transformation: from A to B by Ava Pun
 * Key concepts: math, implementation
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))
#define REP(i, a, b) for (int i = a; i <= (b); ++i)
#define REV(i, a, b) for (int i = a; i >= (b); --i)
#define TRAV(a, x) for (auto &a : x)
#define ALL(x) x.begin(), x.end()
#define SZ(x) (int) (x).size()

using ll = long long;
using pii = pair<int, int>;
using piii = pair<pii, int>;
using vi = vector<int>;
using vii = vector<pii>;
const int INF = 0x3F3F3F3F;
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const int MAX = 2e5 + 5;

int A, B;

void solve() {
    stack<int> st{};

    while (B > 0) {
        if (B == A) {
            cout << "YES\n";
            cout << st.size()+1 << '\n';
            cout << A;
            while (!st.empty()) {
                cout << ' ' << st.top();
                st.pop();
            }
            cout << '\n';
            return;
        }

        st.push(B);
        if (B % 2 == 0) B /= 2;
        else if ((B-1) % 10 == 0) B = (B-1) / 10;
        else break;
    }

    cout << "NO\n";
}

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);

    cin >> A >> B;
    solve();

}
