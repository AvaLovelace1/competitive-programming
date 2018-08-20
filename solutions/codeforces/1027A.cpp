/*
 Solution to Palindromic Twist by Ava Pun
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
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const int MAX = 100 + 5;

int T, N;
char arr[MAX];

int main() {
    
    scanf("%d", &T);
    while (T--) {
        scanf("%d%s", &N, arr);
        bool good = 1;
        for (int i = 0; i < N / 2; i++) {
            int d = abs(arr[i] - arr[N - i - 1]);
            if (d != 0 && d != 2) {
                good = 0;
                break;
            }
        }
        printf(good ? "YES\n" : "NO\n");
    }
    
    return 0;
}
