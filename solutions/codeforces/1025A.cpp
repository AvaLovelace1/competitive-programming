/*
 Solution to Doggo Recoloring by Ava Pun
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
const int MOD = 998244353;
const int MAX = 1e5 + 5;

int N;
char arr[MAX];
int cnt[26];

int main() {
    
    scanf("%d%s", &N, arr);
    for (int i = 0; i < N; i++) {
        cnt[arr[i] - 'a']++;
    }
    bool good = 0;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] > 1) {
            good = 1;
            break;
        }
    }
    if (N == 1) {
        good = 1;
    }
    printf(good ? "Yes\n" : "No\n");

    return 0;
}
