/*
 Solution to Google Kick Start '20 RB P3 - Robot Path Decoding by Ava Pun
 Key concepts: implementation, parsing
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
const int INF = 0x3F3F3F3F;
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9;
const int MAX = 1e5 + 5;
const double EPS = 1e-9;

int T;
string S;
int num[2005];
ll x[2005], y[2005];

int main() {
    
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    for (int test = 1; test <= T; test++) {
        
        cin >> S;
        
        x[1] = y[1] = 0;
        num[1] = 1;
        int ptr = 1;
        for (char c : S) {
            switch (c) {
                case 'N':
                    y[ptr] += -1 + MOD;
                    y[ptr] %= MOD;
                    break;
                case 'S':
                    y[ptr] += 1;
                    y[ptr] %= MOD;
                    break;
                case 'E':
                    x[ptr] += 1;
                    x[ptr] %= MOD;
                    break;
                case 'W':
                    x[ptr] += -1 + MOD;
                    x[ptr] %= MOD;
                    break;
                case '(':
                    break;
                case ')':
                    {
                    ll totX = num[ptr] * x[ptr] % MOD;
                    ll totY = num[ptr] * y[ptr] % MOD;
                    ptr--;
                    x[ptr] = (x[ptr] + totX) % MOD;
                    y[ptr] = (y[ptr] + totY) % MOD;
                    break;
                    }
                default:
                    ptr++;
                    num[ptr] = c - '0';
                    x[ptr] = y[ptr] = 0;
                    break;
            }
        }
        
        cout << "Case #" << test << ": " << x[1] + 1 << " " << y[1] + 1 << "\n";
    }
    
    return 0;
} 
