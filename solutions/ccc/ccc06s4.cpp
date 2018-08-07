/*
 Solution to CCC '06 S4 - Groups by Ava Pun
 Key concepts: implementation
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<pii, pii> piii;
const int INF = 0x3F3F3F3F;

int N;
int arr[105][105];

bool associative() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= N; k++) {
                if (arr[i][arr[j][k]] != arr[arr[i][j]][k]) {
                    return false;
                }
            }
        }
    }
    return true;
}

int identity() {
    bool found;
    for (int i = 1; i <= N; i++) {
        found = true;
        for (int j = 1; j <= N; j++) {
            if (arr[i][j] != j || arr[j][i] != j) {
                found = false;
                break;
            }
        }
        if (found) {
            return i;
        }
    }
    return INF;
}

bool inverse() {
    int iden = identity();
    bool found;
    for (int i = 1; i <= N; i++) {
        found = false;
        for (int j = 1; j <= N; j++) {
            if (arr[i][j] == iden && arr[j][i] == iden) {
                found = true;
                break;
            }
        }
        if (!found) {
            return false;
        }
    }
    return true;
}

int main() {
    
    scanf("%d", &N);
    while (N != 0) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                scanf("%d", &arr[i][j]);
            }
        }
        printf(associative() && identity() != INF && inverse() ? "yes\n" : "no\n");
        scanf("%d", &N);
    }
    
    return 0;
}
