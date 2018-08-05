/*
 Solution to Rated for Me by Ava Pun
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
const int INF = 0x3F3F3F3F;
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;

int R;

int main() {
    
    scanf("%d", &R);
    if (R < 1200) {
        printf("ABC\n");
    } else if (R < 2800) {
        printf("ARC\n");
    } else {
        printf("AGC\n");
    }
    
    return 0;
}
