/*
 Solution to City Game by Ava Pun
 Key concepts: all nearest smaller values
 */

#include <bits/stdc++.h>

using namespace std;

#define FILL(a, b) memset(a, b, sizeof(a))

const int MAX = 1005;

int K, N, M;
int arr[MAX][MAX];
int bound1[MAX], bound2[MAX];
stack<int> st;

int main() {
    
    scanf("%d", &K);
    
    while (K--) {
        
        FILL(arr, 0);
        scanf("%d%d", &N, &M);
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                char c;
                scanf(" %c", &c);
                arr[i][j] = c == 'F';
                if (arr[i][j] != 0) {
                    arr[i][j] += arr[i - 1][j];
                }
            }
        }
        
        int ans = 0;
        for (int i = 1; i <= N; i++) {
            while (!st.empty()) {
                st.pop();
            }
            st.push(0);
            for (int j = 1; j <= M; j++) {
                while (st.top() != 0 && arr[i][st.top()] >= arr[i][j]) {
                    st.pop();
                }
                bound1[j] = st.top();
                st.push(j);
            }
            while (!st.empty()) {
                st.pop();
            }
            st.push(M + 1);
            for (int j = M; j >= 0; j--) {
                while (st.top() != M + 1 && arr[i][st.top()] >= arr[i][j]) {
                    st.pop();
                }
                bound2[j] = st.top();
                st.push(j);
            }
            for (int j = 1; j <= M; j++) {
                ans = max(ans, (bound2[j] - bound1[j] - 1) * arr[i][j] * 3);
            }
        }
        printf("%d\n", ans);
    }
    
    return 0;
}
