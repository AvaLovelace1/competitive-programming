/*
 Solution to WC18 #1 - Essay Generator by Ava Pun
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
const int INF = 0x3F3F3F3F;
const ll INFL = 0x3F3F3F3F3F3F3F3FLL;
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;

int W;

int main() {
    
    scanf("%d", &W);
    
    for (int i = 0; i < 26 && W; i++) {
        printf("%c ", 'a' + i);
        W--;
    }
    
    for (int i = 0; i < 26 && W; i++) {
        for (int j = 0; j < 26 && W; j++) {
            printf("%c%c ", 'a' + i, 'a' + j);
            W--;
        }
    }
    
    for (int i = 0; i < 26 && W; i++) {
        for (int j = 0; j < 26 && W; j++) {
            for (int k = 0; k < 26 && W; k++) {
                printf("%c%c%c ", 'a' + i, 'a' + j, 'a' + k);
                W--;
            }
        }
    }

    return 0;
}
