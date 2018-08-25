/*
 Solution to ECOO '18 R1 P3 - Missing Art by Ava Pun
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

int N, X, Y, Z;
string arr[25], ans[25], check[25];
vi failed;

int main() {

    for (int test = 1; test <= 10; test++) {
        
        string str;
        
        failed.clear();
        cin >> N >> X >> Y >> Z;
        for (int i = 1; i <= N; i++) {
            cin >> arr[i];
        }
        cin >> str;
        for (int i = 1; i <= N; i++) {
            cin >> ans[i];
        }

        for (int i = 1; i <= N; i++) {
            check[i] = "";
            for (int j = 0; j < arr[i].length(); j++) {
                char c = arr[i][j];
                int n = c - '0';
                if (n == 0) {
                    n = Z;
                } else if (n % 2 == 0) {
                    n += X;
                } else {
                    n -= Y;
                    if (n < 0) {
                        n = 0;
                    }
                }
                check[i] += to_string(n);
                if (n < 0) {
                    break;
                }
            }
        }
        
        bool fail = false;
        for (int i = 1; i <= N; i++) {
            if (ans[i] != check[i]) {
                fail = true;
                failed.pb(i);
            }
        }
        
        if (fail) {
            printf("FAIL: ");
            for (int i = 0; i < failed.size(); i++) {
                printf("%d", failed[i]);
                if (i != failed.size() - 1) {
                    printf(",");
                }
            }
            printf("\n");
        } else {
            printf("MATCH\n");
        }
        cin >> str;
    }
    
    return 0;
}
