/*
 Solution to A Times B by Ava Pun
 Key concepts: fast Fourier transform
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
typedef complex<double> cd;
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

string strA, strB;

void fft(vector<cd> &a, bool inv) {

    int n = a.size();
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (i < j) {
            swap(a[i], a[j]);
        }
        int bit = n >> 1;
        while (j & bit) {
            j ^= bit;
            bit >>= 1;
        }
        j ^= bit;
    }

    for (int d = 2; d <= n; d <<= 1) {
        for (int l = 0; l < n; l += d) {
            double angle = 2 * M_PI / d * (inv ? -1 : 1);
            cd curW(1), w(cos(angle), sin(angle));
            for (int i = l; i < l + d / 2; i++) {
                cd a0 = a[i], a1 = curW * a[i + d / 2];
                a[i] = a0 + a1;
                a[i + d / 2] = a0 - a1;
                curW *= w;
            }
        }
    }

    if (inv) {
        for (auto &x : a) {
            x /= n;
        }
    }
}

inline int conv(vector<cd> &a, string &str) { 
    int ans = 1, st = 0;
    if (str[0] == '-') {
        ans = -1;
        st = 1;
    }
    for (int i = 0; i < str.length() - st; i++) {
        a[str.length() - st - i - 1] = str[i + st] - '0';
    }
    return ans;
}

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> strA >> strB;
    int sign = 1;
    int n = 1 << (sizeof(int) * 8 - __builtin_clz(strA.length() + strB.length()));
    vector<cd> a(n), b(n);
    sign *= conv(a, strA);
    sign *= conv(b, strB);
    
    fft(a, 0), fft(b, 0);
    for (int i = 0; i < n; i++) {
        a[i] *= b[i];
    }
    fft(a, 1);

    vi ans(n);
    int carry = 0;
    for (int i = 0; i < n; i++) {
        int digit = (int) round(a[i].real()) + carry;
        ans[i] = digit % 10;
        carry = digit / 10;
    }
    if (sign == -1) {
        cout << '-';
    }
    bool lead = 1;
    for (int i = ans.size() - 1; i >= 0; i--) {
        if (ans[i] != 0 || i == 0) {
            lead = 0;
        }
        if (!lead) {
            cout << ans[i];
        }
    }
    cout << '\n';

    return 0;
}
