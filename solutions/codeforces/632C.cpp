/*
 Solution to The Smallest String Concatenation by Ava Pun
 Key concepts: sorting
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
const int MOD = 1e9 + 7;
const int MAX = 5e4 + 2;
const double EPS = 1e-7;

int N;
string arr[MAX];

inline bool cmp(string &a, string &b) {
    return a + b < b + a;
}

int main() {
    
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    sort(arr + 1, arr + N + 1, cmp);
    for (int i = 1; i <= N; i++) {
        cout << arr[i];
    }
    cout << "\n";
    
    return 0;
}
