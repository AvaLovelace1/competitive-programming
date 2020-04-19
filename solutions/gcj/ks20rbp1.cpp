/*
 Solution to Google Kick Start '20 RB P1 - Bike Tour by Ava Pun
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
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;
const double EPS = 1e-9;

int T;
int N;
int arr[105];

int main() {
    
    scanf("%d", &T);

    for (int test = 1; test <= T; test++) {
        
        scanf("%d", &N);
        for (int i = 1; i <= N; i++) {
            scanf("%d", &arr[i]);
        }

        int ans = 0;
        for (int i = 2; i < N; i++) {
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
                ans++;
            }
        }
        printf("Case #%d: %d\n", test, ans);
    }
    
    return 0;
}
