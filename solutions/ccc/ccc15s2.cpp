/*
 Solution to CCC '15 S2 - Jerseys by Ava Pun
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

int J, A;
char arr[MAX];
bool taken[MAX];

int main() {
    
    scanf("%d%d", &J, &A);
    for (int i = 1; i <= J; i++) {
        scanf(" %c", &arr[i]);
    }
    int n;
    char c;
    for (int i = 1; i <= A; i++) {
        scanf(" %c%d", &c, &n);
        if (arr[n] <= c) {
            taken[n] = true;
        }
    }
    printf("%d\n", accumulate(taken + 1, taken + J + 1, 0));
    
    return 0;
}
