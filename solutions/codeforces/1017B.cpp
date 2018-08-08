/*
 Solution to The Bits by Ava Pun
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
const int MAX = 1e5 + 5;

int N;
char a[MAX], b[MAX];

int main() {
    
    scanf("%d", &N);
    scanf("%s", a), scanf("%s", b);
    ll cnt1 = 0, cnt0 = 0, n1 = 0, n0 = 0;
    for (int i = 0; i < N; i++) {
        if (b[i] == '0') {
            if (a[i] == '1') {
                cnt1++;
            } else {
                cnt0++;
            }
        } else {
            if (a[i] == '1') {
                n1++;
            } else {
                n0++;
            }
        }
    }
    printf("%lld\n", cnt0 * n1 + cnt1 * n0 + cnt0 * cnt1);
    
    return 0;
}
