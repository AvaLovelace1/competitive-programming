/*
 Solution to Double Doors Regional P1 - Tudor Gets a Goat by Ava Pun
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
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

int N, M, P;

int main() {

    scanf("%d%d%d", &N, &M, &P);
    printf(N == M ? "Switch\n" : "Stay\n");
    
    return 0;
}
