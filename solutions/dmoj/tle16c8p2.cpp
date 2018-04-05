/*
 Solution to TLE '16 Contest 8 P2 - Dank Meme by Ava Pun
 Key concepts: implementation, simple math
 */

#include <bits/stdc++.h>

using namespace std;

int T;

int main() {
    
    scanf("%d", &T);
    
    int n;
    string s;
    while (T--) {
        scanf("%d", &n);
        s = "";
        if (n == 0) {
            printf("meme");
        } else {
            while (n) {
                if (n % 2) {
                    s = '1' + s;
                } else {
                    s = '0' + s;
                }
                n /= 2;
            }
            for (char c : s) {
                printf(c == '0' ? "meme " : "dank ");
            }
        }
        
        printf("\n");
    }
    
    return 0;
}
