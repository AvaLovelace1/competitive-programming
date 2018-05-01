/*
 Solution to Sandwich by Ava Pun
 Key concepts: deque
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

ll N;
deque<int> dq;

int main() {

    scanf("%lld", &N);
    char c;
    for (int i = 1; i <= N; i++) {
        scanf(" %c", &c);
        if (c == '0') {
            dq.push_back(i);
        } else {
            dq.push_front(i);
        }
    }
    for (int i = 1; i <= N; i++) {
        printf("%d\n", dq.front());
        dq.pop_front();
    }
    
    return 0;
}
