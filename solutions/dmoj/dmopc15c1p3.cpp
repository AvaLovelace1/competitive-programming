/*
 Solution to DMOPC '15 Contest 1 P3 - Itami and Cipher by Ava Pun
 Key concepts: brute force
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
const int MAX = 1e6 + 5;

string S, T;

int main() {

    cin >> S >> T;
    int i = 0;
    for (; i <= 25; i++) {
        if (S.find(T) != S.npos) {
            break;
        }
        for (int j = 0; j < S.length(); j++) {
            S[j]--;
            if (S[j] < 'a') {
                S[j] = 'z';
            }
        }
    }
    cout << i << '\n' << S << '\n';
    
    return 0;
}
