/*
 Solution to 11172 - Relational Operator by Ava Pun
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
typedef pair<pii, int> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 1e6 + 5;

int N;

int main() {
    
    scanf("%d", &N);
    int a, b;
    while (N--) {
        scanf("%d%d", &a, &b);
        printf("%c\n", a == b ? '=' : a > b ? '>' : '<');
    }
    
    return 0;
}
