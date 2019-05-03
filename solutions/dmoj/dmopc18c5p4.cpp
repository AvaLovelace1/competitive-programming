/*
 Solution to DMOPC '18 Contest 5 P4 - An Art Gallery Problem by Ava Pun
 Key concepts: ad hoc
 */

// Number of components = N + 1
// Worst case number of moves = (N / 2)^2 (0101001010 -> 1010110101)

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
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;

int N;
bool arr1[MAX], arr2[MAX];

// The highest-numbered '1' when the pattern is transformed to 1010... or 0101...
// There are N + 1 possible answers.
int solve(bool arr[]) {
    stack<int> st;
    st.push(0);
    int zeroCnt = 0;
    for (int i = 1; i <= N; i++) {
        if (arr[i]) {
            if (zeroCnt % 2 == 1) {
                // Have to leave a zero in between
                st.push(st.top() + 2);
                zeroCnt--;
            } else {
                // Don't have to leave a zero in between
                if (st.top() == 0) {
                    st.push(1);
                } else {
                    zeroCnt += 3 - (st.top() == 1);
                    st.pop();
                }
            }
        } else {
            zeroCnt++;
        }
    }
    return st.top();
}

int main() {
    
    scanf("%d", &N);
    char c;
    for (int i = 1; i <= N; i++) {
        scanf(" %c", &c);
        arr1[i] = c == 'F';
    }
    for (int i = 1; i <= N; i++) {
        scanf(" %c", &c);
        arr2[i] = c == 'F';
    }
    
    printf(solve(arr1) == solve(arr2) ? "YES\n" : "NO\n");
    
    return 0;
}
