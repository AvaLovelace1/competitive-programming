/*
 Solution to CCC '12 J2 - Sounds fishy! by Ava Pun
 Key concepts: implementation
 */
 
 #include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n1, n2, n3, n4;
    scanf("%d%d%d%d", &n1, &n2, &n3, &n4);
    
    if (n1 == n2 && n2 == n3 & n3 == n4) {
        printf("Fish At Constant Depth");
    } else if (n1 < n2 && n2 < n3 & n3 < n4) {
        printf("Fish Rising");
    } else if (n1 > n2 && n2 > n3 & n3 > n4) {
        printf("Fish Diving");
    } else {
        printf("No Fish");
    }
    
    return 0;
    
}
