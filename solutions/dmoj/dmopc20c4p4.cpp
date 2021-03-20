/*
 Solution to DMOPC '20 Contest 4 P4 - Javelin Throwing by Ava Pun
 Key concepts: greedy algorithms
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
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const int MAX = 5e5 + 2;
const double EPS = 1e-9;

int N;

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    int totMarks = 0;
    ll ans = 0;
    stack<int> st{};

    for (int i = 1; i <= N; ++i) {
        int ki;
        cin >> ki;
        if (ki >= totMarks) {
            for (int j = 1; j <= ki - totMarks; ++j) {
                int prevRepeat = st.top();
                st.pop();
                ans += i - prevRepeat;
            }
            totMarks = ki + 1;
        } else {
            ans += totMarks - ki - 1;
            st.push(i);
        }
        cout << ans << (i < N ? ' ' : '\n');
    }
    
}
