/*
 Solution to COCI '06 Contest 5 #2 Natrij by Ava Pun
 Key concepts: implementation
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<pii, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;

string S[2];
int arr[2][4];
int ans[4];

int main() {

    cin >> S[0] >> S[1];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            arr[i][j + 1] = (S[i][3 * j] - '0') * 10 + (S[i][3 * j + 1] - '0');
        }
    }

    for (int i = 3; i >= 1; i--) {
        if (arr[1][i] < arr[0][i]) {
            arr[1][i] += i == 1 ? 24 : 60;
            int idx = i - 1;
            while (idx > 0 && arr[1][idx] == 0) {
                arr[1][idx] = idx == 1 ? 23 : 59;
                idx--;
            }
            arr[1][idx]--;
        }
        ans[i] = arr[1][i] - arr[0][i];
    }
    if (ans[1] == 0 && ans[2] == 0 && ans[3] == 0) {
        ans[1] = 24;
    }
    cout << setfill('0') << setw(2) << ans[1];
    cout << ':';
    cout << setfill('0') << setw(2) << ans[2];
    cout << ':';
    cout << setfill('0') << setw(2) << ans[3];
    cout << '\n';
    
    return 0;
}
