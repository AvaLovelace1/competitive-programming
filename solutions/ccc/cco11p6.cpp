/* 
 Solution to CCO '11 P6 - Biggest (Zero Carbon) Footprint by Ava Pun
 Key concepts: all nearest smaller values
*/

#include <bits/stdc++.h>

using namespace std;

int N, M, T;
short int arr[10005][10005] = {};
pair<short int, short int> bounds[10005];

int main() {
    
    scanf("%d%d%d", &N, &M, &T);
    int x, y;
    while (T--) {
        scanf("%d%d", &x, &y);
        if (x > 0) {
            arr[x - 1][y] = 1;
        }
    }
    for (int i = 0; i <= N; i++) {
        arr[i][0] = N - i;
        arr[i][M] = N - i;
    }
    for (int i = 0; i <= M; i++) {
        arr[N - 1][i] = 1;
    }
    for (int i = N - 2; i >= 0; i--) {
        for (int j = 1; j < M; j++) {
            if (arr[i][j] == 0) {
                arr[i][j] = arr[i + 1][j] + 1;
            }
        }
    }
    
    stack<int> s;
    int maxArea = N;
    for (int i = 0; i < N; i++) {
        s.push(0);
        for (int j = 0; j <= M; j++) {
            while (s.top() != 0 && arr[i][s.top()] >= arr[i][j]) {
                s.pop();
            }
            bounds[j].first = s.top();
            s.push(j);
        }
        while (!s.empty()) {
            s.pop();
        }
        s.push(M);
        for (int j = M; j >= 0; j--) {
            while (s.top() != M && arr[i][s.top()] >= arr[i][j]) {
                s.pop();
            }
            bounds[j].second = s.top();
            s.push(j);
        }
        while (!s.empty()) {
            s.pop();
        }
        for (int j = 0; j <= M; j++) {
            maxArea = max(maxArea, (bounds[j].second - bounds[j].first) * arr[i][j]);
        }
    }

    printf("%d", maxArea);
    
}
