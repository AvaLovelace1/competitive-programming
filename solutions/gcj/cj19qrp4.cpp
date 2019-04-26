/*
 Solution to Google Code Jam '19 QR P4 - Dat Bae by Ava Pun
 Key concepts: ad hoc
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3f3f3f3f;
const int MAX = 5e6 + 5;

int T, N, B, F;
string arr[1025];

inline void quer(string str) {
    cout << str << '\n';
    fflush(stdout);
    string ans;
    cin >> ans;
    if (ans == "-1") {
        exit(0);
    }
    for (int i = 0; i < N - B; i++) {
        arr[i] += ans[i];
    }
}

int main() {

    cin >> T;
    for (int testN = 1; testN <= T; testN++) {
        cin >> N >> B >> F;
        for (int i = 0; i < N - B; i++) {
            arr[i] = "";
        }
        for (int i = 0; i < 4; i++) {
            string str = "";
            for (int j = 0; j < N; j++) {
                str += ((j % 16) & (1 << i)) == 0 ? '0' : '1';
            }
            quer(str);
        }
        vi ans;
        int idx = 0;
        string cur;
        for (int j = 0; j < N; j++) {
            cur = "";
            for (int i = 0; i < 4; i++) {
                cur += ((j % 16) & (1 << i)) == 0 ? '0' : '1';
            }
            if (idx >= N - B || arr[idx] != cur) {
                ans.pb(j);
            } else {
                idx++;
            }
        }
        for (int i : ans) {
            cout << i << ' ';
        }
        cout << '\n';
        fflush(stdout);
        cin >> cur;
        if (cur == "-1") {
            exit(0);
        }
    }

    return 0;
}
