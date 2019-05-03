/*
 Solution to DMPG '19 S3 - Chemical Counting Capers by Ava Pun
 Key concepts: difference array, stack
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
const int MAX = 1e6 + 5;

int N, N1 = 0;
ll diff[MAX];
int arr[MAX];
string elem[MAX];
ll num[27][27];

ll modPow(ll a, ll b) {
    if (b == 0) {
        return 1;
    } else {
        ll ans = modPow(a * a % MOD, b / 2);
        if (b & 1) {
            ans = ans * a % MOD;
        }
        return ans;
    }
}

inline void upd(int l, int r, int x) {
    diff[l] = diff[l] * x % MOD;
    diff[r + 1] = diff[r + 1] * modPow(x, MOD - 2) % MOD;
}

int main() {
    
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    assert(N >= 1 && N <= 1000000);
    for (int i = 0; i <= N; i++) {
        diff[i] = 1;
    }

    string str;
    int n;
    stack<int> st;
    for (int i = 1; i <= N; i++) {
        cin >> str;
        if (str == "(") {
            st.push(N1 + 1);
        } else if (str == ")") {
            cin >> n;
            assert(!st.empty());
            upd(st.top(), N1, n);
            st.pop();
        } else {
            N1++;
            if (str.length() == 1) {
                str += 'a' - 1;
            }
            elem[N1] = str;
            cin >> n;
            arr[N1] = n;
        }
    }
    assert(st.empty());

    for (int i = 1; i <= N1; i++) {
        diff[i] = diff[i] * diff[i - 1] % MOD;
    }
    for (int i = 1; i <= N1; i++) {
        num[elem[i][0] - 'A' + 1][elem[i][1] - 'a' + 1] += arr[i] * diff[i] % MOD;
        num[elem[i][0] - 'A' + 1][elem[i][1] - 'a' + 1] %= MOD; 
    }
    for (int i = 0; i < 27; i++) {
        for (int j = 0; j < 27; j++) {
            if (num[i][j] != 0) {
                printf("%c", i + 'A' - 1);
                if (j != 0) {
                    printf("%c", j + 'a' - 1);
                }
                printf(" %lld\n", num[i][j]);
            }
        }
    } 
    
    return 0;
}
