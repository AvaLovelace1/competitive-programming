/*
 Solution to ECOO '14 R2 P1 - Scratch and Win by Ava Pun
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

map<int, int> arr;
int prizes[] = {1, 2, 5, 10, 50, 100, 1000, 10000, 500000, 1000000};

int main() {
    
    for (int test = 1; test <= 10; test++) {
        arr.clear();
        char c;
        int n;
        for (int i = 1; i <= 9; i++) {
            scanf(" %c", &c);
            if (c == '$') {
                scanf("%d", &n);
            } else {
                n = -1;
            }
            arr[n]++;
        }
        bool found = false;
        for (int i : prizes) {
            if (arr[i] >= 3) {
                printf("$%d", i);
                found = true;
                break;
            }
        }
        if (!found) {
            for (int i : prizes) {
                if (arr[i] + arr[-1] >= 3) {
                    if (found) {
                        printf(" ");
                    } else {
                        found = true;
                    }
                    printf("$%d", i);
                }
            }
        }
        if (!found) {
            printf("No Prizes Possible");
        }
        printf("\n");
    }
    
    return 0;
}
