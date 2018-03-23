/*
 Solution to Binary by Ava Pun
 Key concepts: simple math
 */

#include <bits/stdc++.h>

using namespace std;

int N;

int main() {
    
    scanf("%d", &N);
    int n;
    while (N--) {
        scanf("%d", &n);
        if (n == 0) {
            printf("0000");
        } else {
            string ans = "";
            while (n > 0) {
                ans = to_string(n % 2) + ans;
                n /= 2;
            }
            long len = ans.length();
            for (int i = 1; i <= (4 - len % 4) % 4; i++) {
                ans = "0" + ans;
            }
            for (int i = 0; i < ans.length(); i++) {
                printf("%c", ans[i]);
                if (i % 4 == 3) {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
    
    return 0;
    
}
