/*
 Solution to DMOPC '18 Contest 6 P0 - SQL Queries by Ava Pun
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
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;

int arr[4];
vi v;

int main() {
    
    for (int i = 1; i <= 3; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] != 0) {
            v.pb(i);
        }
    }
    if (v.size() <= 1) {
        printf("YES\n");
    } else if (v.size() == 2) {
        printf((arr[v[0]] == v[1] && arr[v[1]] == v[0]) ? "NO\n" : "YES\n");
    } else {
        printf("NO\n");
    }
    
    return 0;
}
