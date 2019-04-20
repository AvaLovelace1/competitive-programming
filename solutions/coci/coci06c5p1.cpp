/*
 Solution to COCI '06 Contest 5 #1 Trik by Ava Pun
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

string S;
bool arr[3];

int main() {

    arr[0] = 1;
    cin >> S;
    for (char c : S) {
        if (c == 'A') {
            swap(arr[0], arr[1]);
        } else if (c == 'B') {
            swap(arr[1], arr[2]);
        } else {
            swap(arr[0], arr[2]);
        }
    }
    cout << (int) (max_element(arr, arr + 3) - arr) + 1 << '\n';
    
    return 0;
}
