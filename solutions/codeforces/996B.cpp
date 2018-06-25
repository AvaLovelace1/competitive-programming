/*
 Solution to World Cup by Ava Pun
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
const int MAX = 1e5 + 5;

int N;
int arr[MAX];

int main() {

    scanf("%d", &N);
    int minN = INF;
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
        minN = min(minN, arr[i]);
    }
    for (int i = 0; i < N; i++) {
        arr[i] -= minN;
    }
    
    int pos = minN % N;
    int cnt = 0;
    while (arr[pos] - cnt > 0) {
        pos = (pos + 1) % N;
        cnt++;
    }
    printf("%d\n", pos + 1);
    
    return 0;
}
