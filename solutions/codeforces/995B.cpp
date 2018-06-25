/*
 Solution to Suit and Tie by Ava Pun
 Key concepts: greedy algorithms
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
const int MAX = 205;

int N;
int arr[MAX];

int main() {
    
    scanf("%d", &N);
    for (int i = 1; i <= 2 * N; i++) {
        scanf("%d", &arr[i]);
    }
    
    int cnt = 0;
    for (int i = 1; i <= 2 * N; i++) {
        int j = i + 1;
        while (arr[j] != arr[i] && j <= 2 * N) {
            j++;
        }
        if (j <= 2 * N) {
            while (arr[j - 1] != arr[i]) {
                swap(arr[j], arr[j - 1]);
                cnt++;
                j--;
            }
        }
    }
    printf("%d\n", cnt);
    
    return 0;
}
