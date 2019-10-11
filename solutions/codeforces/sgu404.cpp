/*
 Solution to Fortune-telling with camomile by Ava Pun
 Key concepts: implementation, simple math
 */

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long int ll;
typedef pair<ll, ll> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;
const double EPS = 1e-9;

int N, M;
string arr[105];

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        cin >> arr[i];
    }
    arr[0] = arr[M];
    cout << arr[N % M] << '\n';

    return 0;
}
