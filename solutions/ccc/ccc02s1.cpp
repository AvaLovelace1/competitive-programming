/*
 Solution to CCC '02 S1 - The Students' Council Breakfast by Ava Pun
 Key concepts: brute force
 */

#include <bits/stdc++.h>

using namespace std;

int P, G, R, O, N;

int main() {
    
    scanf("%d%d%d%d%d", &P, &G, &R, &O, &N);
    
    int minN = INT_MAX, cnt = 0;
    for (int i = 0; i * P <= N; i++) {
        for (int j = 0; j * G <= N; j++) {
            for (int k = 0; k * R <= N; k++) {
                for (int l = 0; l * O <= N; l++) {
                    if (i * P + j * G + k * R + l * O == N) {
                        printf("# of PINK is %d # of GREEN is %d # of RED is %d # of ORANGE is %d\n", i, j, k, l);
                        minN = min(minN, i + j + k + l);
                        cnt++;
                    }
                }
            }
        }
    }
    
    printf("Total combinations is %d.\nMinimum number of tickets to print is %d.\n", cnt, minN);
    
    return 0;
}
