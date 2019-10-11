/*
 Solution to Bulls and Cows by Ava Pun
 Key concepts: implementation
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

char arr[2][4];

int main() {

    scanf("%s%s", arr[0], arr[1]); 
    int a = 0, b = 0;
    for (int i = 0; i < 4; i++) {
        a += arr[0][i] == arr[1][i];
        for (int j = 0; j < 4; j++) {
            b += arr[0][i] == arr[1][j] && i != j;
        }
    }
    printf("%d %d\n", a, b);

    return 0;
}
